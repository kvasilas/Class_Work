/*
 * Hw1d 
 * Kirk Vasilas
 * Collaborators - Christopher Keenan
 *I pledge my honor that i have abided by the stevens honor code
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
  //print sum 1, sum 2, and sum 1- sum 2
  double d1 = 0; // sum 1 double
  double d2 = 0; // sum 2 double

  float f1 = 0; // sum 1 float
  float f2 = 0; // sum 2 float

  double i = 0;

  for(i=1; i<=100; i++){ // sum 1 double
    d1 = d1 + (1/(i));
  }

  for(i=100; i>=1; i--){ // sum 2 double
    d2 = d2 + (1/i);
  }
//----------------------------------------------------------------
  for(i=1; i<=100; i++){ // sum 1 float
    f1 = f1 + (1/(i));
  }

  for(i=100; i>=1; i--){ // sum 2 float
    f2 = f2 + (1/i);
  }

  cout <<"Using double Sum1 = " << d1 << endl;
  cout <<"Using double Sum2 = " << d2 << endl;
  cout <<"Sum1 - Sum2 = " << d1-d2 << endl;
  cout <<"------------------------------------------" << endl;
  cout <<"Using float Sum1 = " << f1 << endl;
  cout <<"Using float Sum2 = " << f2 << endl;
  cout <<"Sum1 - Sum2 = " << f1-f2 << endl;
}
