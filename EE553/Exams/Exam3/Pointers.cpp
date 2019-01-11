#include <iostream>
using namespace std;

int main(){
  int a = 2;
  int *p = &a;
  cout << a << '\n'; // 2
  cout << *p << '\n'; // 2
  //delete p; cannot because it was never created
  int *q = new int[1024]; // using "new"
  delete [] q;
}
