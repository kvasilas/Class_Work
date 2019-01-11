/*
 * Hw1a - 3n+1 conjecture
 * Kirk Vasilas
 *I pledge my honor that i have abided by the stevens honor code
*/
#include <iostream>
using namespace std;

int main()
{
  //if n is odd ---> n = 3n+1
  // if n is even -> n = n/2

 int n = 0;

 cout << "input a number  ";
 cin >> n;


 while (n != 1 )
 {
 if (n % 2 == 0) { // if n is even divide by two
     n = n/2;
 }
 else {
     n=3*n+1;
     //     n = 3n+1;
}
 cout << n << ",   ";
 }
 return 0;
}
