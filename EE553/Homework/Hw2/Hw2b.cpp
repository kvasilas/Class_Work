/*
 * Hw2b
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

    /*  This is what i used to test it
    cout << "x"<< x << endl;
    cout << "p"<< p << endl;
    cout << "i"<< i << endl;
    */
  }
}

int main(){
  int n;
  cout << "enter a number" << endl;
  cin >> n;
  //cout<<"isPrime"<< isPrime(n);

  cout << n;
  if(isPrime(n) == 1){
    cout << " is prime" << endl;
  }
  else{
    cout << " is not prime";
  }

}
