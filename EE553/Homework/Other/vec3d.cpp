/*

  * Hw4a - Vec3d
  * Kirk Vasilas
  * Collaborators - Christopher Keenan
  *I pledge my honor that i have abided by the stevens honor code

 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Vec3d {
  private:
    double x, y, z;

  public:
    Vec3d(double xdirect, double ydirect, double zdirect){
      x = xdirect;
      y = ydirect;
      z = zdirect;
    }
    Vec3d(double xdirect, double ydirect){
      x = xdirect;
      y = ydirect;
      z = 0.0;
    }
    Vec3d(double xdirect){
      x = xdirect;
      y = 0.0;
      z = 0.0;
    }
    Vec3d(){
      x = 0.0;
      y = 0.0;
      z = 0.0;
    }

    Vec3d dot(Vec3d right) const {
      return Vec3d(this->x*right.x, this->y*right.y, this->z*right.z);
    }

    Vec3d mag() const{ // square root of sum of square
      Vec3d result(this->x*this->x + this->y*this->y + this->z*this->z);
      return Vec3d double sqrt (result);
    }

    Vec3d magSq() const{ // square root of sum of square
      return Vec3d (this->x*this->x + this->y*this->y + this->z*this->z);
    }

    double Vec3d dist(Vec3d right) {

    }

    friend ostream& operator <<(ostream& s, Vec3d v);
    friend Vec3d operator +(Vec3d left, Vec3d right);
    friend Vec3d operator -(Vec3d left, Vec3d right);
};

ostream& operator <<(ostream& s, Vec3d v) {
  s << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
}

Vec3d operator +(Vec3d left, Vec3d right){
  return Vec3d(left.x + right.x, left.y + right.y, left.z + right.z, 0, 0);
}

Vec3d operator -(Vec3d left, Vec3d right){
  return Vec3d(left.x - right.x, left.y - right.y, left.z - right.z);
}

int main() {
  // use friend operators
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d d(); // d is a function that returns Vec3d
	const Vec3d e;

	const Vec3d f = a + e;
	const Vec3d g = b - d; // d is not an object, pick a different one
	double x = dot(f, g); // regular function
	double y = Vec3d::dot(f,g); // static function
	double z = f.dot(g); // method
	const Vec3d h = -b;

	double dist = f.mag(); // square root of sum of square
	double dist2 = f.magSq(); // sum of square
	double dist3 = f.dist(g); // sqrt or sum of square of diff
	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';
	cout << e << '\n';
	cout << f << '\n';
	cout << g << '\n';
	cout << h << '\n';
}
