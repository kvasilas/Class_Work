/*
 * Hw2c
 * Kirk Vasilas
 * Collaborators - Christopher Keenan
 *I pledge my honor that i have abided by the stevens honor code
*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned long long p){
  int x;
  for (int i = 2; i <= p ; i++) {
    x = p % i;
    if(i == p){
      return true; // pime 1
      break;
    }

    if(x == 0){
      return false; // not prime 0
      break;
    }
  }
}

int countPrimes(unsigned long long a, unsigned long long b){
  int num = 0;
  for (int i = a; i <= b; i++) {
    if(isPrime(i) == 1){
      num++;
    }
    else{
      num = num;
    }
  }

  return num;
}

int main(){
  //compute the primes from range [a,b]

  int a, b;
  cout << "Input the lower number then the higher one" << endl;
  cin >> a >> b;
  cout << "In the range [" << a << "," << b << "], there are " << countPrimes(a,b) << " prime numbers.";
}
