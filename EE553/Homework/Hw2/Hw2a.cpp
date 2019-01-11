/*
 * Hw2a
 * Kirk Vasilas
 * Collaborators - Christopher Keenan
 *I pledge my honor that i have abided by the stevens honor code
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  // wind chill (WC) = 35.74 + .6215T - 35.75(V^.16)+.4275T(V^.16)
  int v;/*wind chill*/
  int t;/*temp for rest*/
  int Temp;/*temp for first row*/
  int z;
  cout << '\t';

  for(Temp = 40; Temp >= -45; Temp-=5){
    cout << Temp << '\t';
  }
cout << endl;
  for (v = 5; v <= 60; v+=5) {
    cout << v << '\t'; //column 1
    for (t = 40; t >= -45 ; t-=5) {
      z = 35.74 + 0.6215*t - 35.75*pow(v,0.16) + 0.427*t*pow(v,0.16);
      cout << z << '\t';
    }
    cout << endl;
  }
return 1;
}
