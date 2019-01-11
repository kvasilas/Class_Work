/*
  * Hw3c - Robot location Esimator
  * Kirk Vasilas
  * Collaborators - Christopher Keenan, Kevin Largacha
  *I pledge my honor that i have abided by the stevens honor code
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

double polar2Rect(double r,double theta,double dx,double dy){
  double pi =  3.141592653589793238;
  dx = dx + r*sin(theta*pi/180);
  dy = dy + r*cos(theta*pi/180);
}

int main(){
  double x = 0; //starting location x
  double y = 0; //starting location y
  // puts the robot at global coordinates (0,0)
  ifstream input("robotpath.dat");
  string linein;
  getline(input,linein);
  while(!input.eof()){
    getline(input, linein);
    istringstream line(linein);
    double r,theta;
    line >> r >> theta;
    polar2Rect(r,theta,x,y);
    cout << "x = " << x << "y = " << y << '\n';
  }
}
