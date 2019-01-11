#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// global variable
int var;

int main(){
  int *pal_of_x; //pointer
  int x = 10;
  int y = 20;
  cout << "value of x is " << x << endl;
  cout << "the adress of x is " << &x << endl;

  pal_of_x = &x;  //adress of x

  x = 20;
  cout << x << endl;
  cout << "the other way the adress is " << pal_of_x << endl;
  *pal_of_x = 30;

  cout << *pal_of_x << endl;
  cout << x << endl;

}
