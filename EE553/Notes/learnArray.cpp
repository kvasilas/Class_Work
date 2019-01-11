#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

//Number arrays////////////////////////////////////////
/*
  int n;
  //input an array of from a[0] to a[n], length of n+1
  cout << "n = ?" << endl;
  cin >> n;
  int a[n+1] = {0, 1, 2, 3, 4, 5};
  cout << "first" << endl;
  for (int i = 0; i <= n; i++) {
    cout << a[i] << ", ";
  }
  // reverse the array
  cout << endl << "backwards" << endl;;
  for (int i = n; i >= 0; i--) {
    cout << a[i] << ", ";
  }
  // change the value of a[j] to 69
  int j;
  cout << "j = ?" << endl;
  cin >> j;
  a[j] = 69;
  cout << "second try" << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << ", ";
  }
*/

//Strings///////////////////////////////////////////////
  /*
  //word as an array of chars
  char word[4] = "fox"; // 3 is too small to use
  cout << word << '\n';
  //word as a string
  string w2 = "fisherman";
  cout << w2 <<'\n';
  //fun fact strings are jsut pre made objects apparently
  // reverse word
  for (int i = w2.length(); i >= 0; i--) {// converst to an array of char
    cout << w2[i];
  }
  */

//Read in a file and import to an array///////////////////

  //mini project.  read in file and use the first number as the number of elements in the array
  double g;
  int n = 256;
  double array[n];
  int i = 0;
  ifstream test("grades2.txt");//import info from "file" and call it test
  while (!test.eof()) {//!NAME.eof() tests to see if it is empty
    test >> array[i];
    i++;
  }// puts the values into array

  n = array[0]; // as per his instructions array uses the first number as the number of elements
  cout << "array is " << n << " spaces long "<< '\n';
  for (int i = 1; i <= n; i++) {
    cout << array[i] << " ";
  }


//Arrays and nested loops//////////////////////////////
/*
  //example - make a 5x5 multiplication table
  const int n = 5;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << i*j << '\t';
    }
    cout << '\n';
  }
*/

}
