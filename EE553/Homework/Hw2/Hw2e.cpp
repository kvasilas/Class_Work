/*
 * Hw2e
 * Kirk Vasilas
 * Collaborators - Christopher Keenan
 *I pledge my honor that i have abided by the stevens honor code
*/

#include <iostream>
#include <cmath>
using namespace std;

//-----------------------------------------------------------------
double fact(int n){
  double f=1;
  for ( int i = n; i>=1.0 ; i--) {
        //cout << " * "<< i ;
        f = f * i;
  }
  return f;
}
//-----------------------------------------------------------------
long fact2(int n){
  if(n > 1)
    return n * fact2(n-1);
  else
    return 1;
}
//-----------------------------------------------------------------
int fibo(int n){
  int x = 0;
  int y = 1;
  int z;
  if(n == 0)
    return x;
  for (int i = 2; i <= n; i++) {
    z = x + y;
    x = y;
    y = z;
  }
  return z;
}
//-----------------------------------------------------------------
int fibo2(int n){
  if(n<=1)
    return n;
  return fibo2(n-1) + fibo2(n-2);
}
//-----------------------------------------------------------------
double choose(int n, int r){
  double result = 1;
  result = fact(n) / (fact(r)*fact(n-r));
  return result;
}
//-----------------------------------------------------------------


int main() {

  cout << "factorial of 5: using loop = "  << fact(5)  << "  using recursion = " << fact2(5)  << '\n';
  cout << "factorial of 15: using loop = " << fact(15) << "  using recursion = " << fact2(15) << '\n';
  cout << "Fibonacci 5: using loop = "  << fibo(5)  << "  using recursion = " << fibo2(5)  << '\n';
  cout << "Fibonacci 13: using loop = " << fibo(13) << "  using recursion = " << fibo2(13) << '\n';
  cout << "Number of ways to play the NY lottery  = " << choose(52, 6) << '\n';
}
