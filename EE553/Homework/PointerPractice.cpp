/*
  * Pointer Practice
  * Kirk Vasilas
  * Collaborators - Christopher Keenan, Kevin Largacha
  *I pledge my honor that i have abided by the stevens honor code
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class PointerPractice{
  private:
    char a;
    char b;
  public:
    PointerPractice(){
      char a[40][50];
    }
    void fillWithZero(){
      char a[40*50]  = {0};
    }
    void setRow(int z, char b){
      for (int i = 0; i < 50; i++) {
        return char a[z][i];
      }
    }
    void print(){
      cout << a << endl;
    }
};

int main() {
  PointerPractice p; // create the object containing the 2d array
  p.fillWithZero();
  p.print();
  p.setRow(4, '1'); // set every element in row 4 to the letter 1
  p.print(); // print again.
}
