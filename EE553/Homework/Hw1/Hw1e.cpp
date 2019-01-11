/*
 * Hw1e - read number and compute n factorial
 * Kirk Vasilas
 * Collaborators - Christopher Keenan
 *I pledge my honor that i have abided by the stevens honor code
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n = 0;
  int i = 0;
  int fact = 1;

  cout << "enter a number for n" << endl;
  cin >> n;
  cout << "n = " << n << "! =  ";

  for (size_t i = n; i>1 ; i--) {
    cout << i << " * ";
    fact = fact * i;
  }
  cout << "1 = " << fact << endl;

}
