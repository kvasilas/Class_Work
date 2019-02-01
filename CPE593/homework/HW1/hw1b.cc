/*
 * Homework # : HW1b Choose(n,r)
 * Due: 2/1/19
 * Name: Kirk Vasilas
 * Collaboraters: Justin Trugmann, Dave Lehman
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 * Compiles with g++ -std=c++11 for chrono
 */
#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

double choose_unef(int n, int r){
    if(r == 0 || r == n){
        return 1;
    }
    return choose_unef(n-1, r) + choose_unef(n-1, r-1);
}

double choose_eff(int n, int r){
    static int memoize[n+1][r+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <=min(i,r); j++){
            if(j == 0 || j == i ){
                memoize[i][j] = 1;
            }
            else {
                memoize[i][j] = memoize[i-1][j-1] + memoize[i-1][j];
            }
        }
    }
    return memoize[n][r];
}

int main() {
    int numTrials = 100;
    cout << "enter number of trials" << endl;
    cin >> numTrials;
    //100 trials = 0.107s
    //1000 trials = 2.821s
    //10,000 trials = 22.517s
    //100,000 trials = 27.317s, 26.674s
    //1,000,000 trials stopped at 4 min

	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,500);

    auto start = high_resolution_clock::now();
    for (int i = 0; i < numTrials; i++) {
		int n = distribution(generator);
		uniform_int_distribution<int> rdist(0,n);
		int r = rdist(generator);
        choose_eff(n,r);
	}
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << numTrials <<" memoized trials: " << duration.count() << " milliseconds"<< endl;
    cout << "un-memoized way is too slow. "<< "The code to compare the times is below commented out"<< endl;

    /*
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < 1; i++) {
		int n = distribution(generator);
		uniform_int_distribution<int> rdist(0,n);
		int r = rdist(generator);
        choose_unef(n,r);
	}
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << 1 <<" unmemoized trials: " << duration1.count() << " milliseconds"<< endl;
    */
}
