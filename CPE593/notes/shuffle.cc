#include <random>
#include <iostream>
using namespace std;

default_random_engine generator;

void fisher_yates(int a[], int n){
    for (int i = n-1 ; i > 0; i--) {
        uniform_int_distribution<int> dist(0,i);
        swap(x[i], x[dist(generator)]);
    }
}

void bad_shuffle(){
    uniform_int_distribution<int> dist(0,n-1);
    for (int i = n-1; i > 0; i--) {
        swap(x[i], x[dist(generator)]);
    }
}

void test_shuffle(int n, int trials){
    int a[n];
    int histogram[n][n];
    for (int i = 0; i < trials; i++){
        for (int j = 0; j < count; j++)
            a[i]= i;
        bad_shuffle(a,n);
        fisher_yates(a,n);
    }
}

int int main() {
    generator.seed(0);
    int n = 10;
    int trials = 10;
    test_shuffle(n, trials);
    for (int i = 0; i < 20; i++)
        cout << dist(generator);
    cout << '\n';
    return 0;
}
