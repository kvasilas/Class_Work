#include <iostream>
#include <cmath>
using namespace std;

class Vec3d {
  private:
    double x,y,z;
  public:
    Vec3d() : x(0.0) , y(0.0), z(0.0) {}
    Vec3d(double x, double y, double z) : x(x) , y(x), z(x) {}
    Vec3d(double x, double y) : x(x) , y(x), z(0.0) {}
    Vec3d(double x) : x(x) , y(0.0), z(0.0) {}

    friend Vec3d operator+(const Vec3d& a, const Vec3d& b);
    friend Vec3d operator*(const Vec3d& a, int b);
    friend Vec3d operator*(int b, const Vec3d& a);
    Vec3d& operator=(const Vec3d& a){
      x = a.x;
      y = a.y;
      z = a.z;
    }

    double dot(const Vec3d& a){
      double ans = (x*a.x)+(y*a.y)+(z*a.y);

      return ans;
    }
    double dist(const Vec3d& a){
      double ans = sqrt(pow((x-a.x),2)+pow((y-a.y),2)+pow((z-a.z),2));
      return ans;
    }
};

  Vec3d operator+(const Vec3d& a, const Vec3d& b){
    Vec3d ans;
    ans.x = a.x + b.x;
    ans.y = a.y + b.y;
    ans.z = a.z + b.z;
    return Vec3d(ans.x, ans.y, ans.z);
  }

  Vec3d operator*(const Vec3d& a, int b){
    Vec3d ans;
    ans.x = a.x * b;
    ans.y = a.y * b;
    ans.z = a.z * b;
    return Vec3d(ans.x, ans.y, ans.z);
  }

  Vec3d operator*(int b, const Vec3d& a){
    Vec3d ans;
    ans.x = a.x * b;
    ans.y = a.y * b;
    ans.z = a.z * b;
    return Vec3d(ans.x, ans.y, ans.z);
  }

 double dot(Vec3d& a, Vec3d& b){
   double ans = (b.x*a.x)+(b.y*a.y)+(b.z*a.y);

   return ans;
 }

 double dist(Vec3d& a, Vec3d& b){

 }

int main() {
	Vec3d a(1.0, 2.5, 3.0);
	Vec3d b(1.0, 2.5); // z=0
	Vec3d c(1.0); // y,z = 0
	Vec3d d; // x,y,z=0
	//	Vec3d e(); //THIS IS A FUNCTION!!!
	Vec3d e = a * 2; // scalar multiplication
	Vec3d f = 2 * a; // reverse direction
	Vec3d g = a + b; // vector addition
	Vec3d h = a - b; // vector subtraction
	double z1 = dot(a,b); // function
	double z2 = a.dot(b); // method
	// add static later
	double w1 = a.dist(b);
	double w2 = dist(a,b);
