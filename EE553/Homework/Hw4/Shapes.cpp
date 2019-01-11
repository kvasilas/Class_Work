/*
  * Homework Polymorphism
  * Kirk Vasilas
  * Collaborators - Christopher Keenan, Kevin Largacha
  *I pledge my honor that i have abided by the stevens honor code
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Shape{
  private:
  public:
    virtual double area() = 0;
};

class Rect : public Shape{
  private:
    double l, w;
  public:
    Rect(double width, double length) {
      l = length;
      w = width;
    }
    double area(){
      return (w*l);
    }
    double perimeter(){
      return(2*w+2*l);
    }
};

class Circle : public Shape{
  private:
    double r;
    double pi = 3.141592653589793238;
  public:
    Circle(double radius){
      r = radius;
    }
    double area(){
      return(pi * pow(r,2));
    }
    double perimeter(){
      return (2 * pi * r);
    }
};

int main() {
  Rect r(5.0, 4.0);
  cout << r.area() << '\n';  // should print out 20
  cout << r.perimeter() << '\n'; // should print 18
  Circle c(2);
  cout << c.area() << '\n';  // should be pi*r2 about 12.4
  cout << c.perimeter() << '\n'; // should be 2*pi*r about 12.28
  Shape* s = &r;
  cout << s->area() << '\n'; // polymorphic call
  s = &c;
  cout << s->area() << '\n';// polymorphic call
}
