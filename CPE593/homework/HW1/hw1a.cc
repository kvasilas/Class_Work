/*
 * Homework # : HW1a Eratosthenes
 * Due: 2/1/19
 * Name: Kirk Vasilas
 * Cite: Justin Trugman, Dave Lehman
 * https://www.geeksforgeeks.org/c-program-for-sieve-of-eratosthenes/
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void eratosthenes (int n) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int i = 2; i*i <= n; i++){
        if(prime[i] == true){
            for (int j=i*i; j<=n; j += i){prime[j] = false;}
        }
    }
    //count primes
    int sum =0;
    for (int64_t i = 2; i < sizeof(prime); i++) {sum +=prime[i];}

    cout << sum <<'\n';
}


int main (){
    eratosthenes(100);
}
