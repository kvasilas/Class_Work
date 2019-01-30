/*
 * Homework # : HW1b Choose(n,r)
 * Due: 2/1/19
 * Name: Kirk Vasilas
 * Collaboraters: Justin Trugmann, Dave Lehman
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 */
#include <iostream>
#include <random>
using namespace std;

double choose_unef(int n, int r){
    if(r == 0 || r == n){
        return 1;
    }
    return choose_unef(n-1, r) + choose_unef(n-1, r-1);
}

double choose_eff(int n, int r){
    int memoize[n+1][r+1];
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
    int numTrials = 100000;
	//  cin >> numTrials;
    //100 trials = 0.107s
    //100 trials = 2.821s
    //10,000 trials = 22.517s
    //100,000 trials = 27.317s, 26.674s
    //1,000,000 trials stopped at 4 min

	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,500);

    for (int i = 0; i < numTrials; i++) {
		int n = distribution(generator);
		uniform_int_distribution<int> rdist(0,n);
		int r = rdist(generator);
        choose_eff(n,r);
	}
}
