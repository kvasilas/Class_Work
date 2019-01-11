/*
	Make the following main work by writing a class Complex.

  * Hw4a - vec3d
  * Kirk Vasilas
  * Collaborators - Christopher Keenan, Kevin Largacha
  *I pledge my honor that i have abided by the stevens honor code

  Notice that since objects are const, you will have to promise not to change them
 */

 #include<fstream>
 #include <iostream>
 #include <cmath>
 using namespace std;

 class Vec3d{
  private:
   double x,y,z;
  public:

   Vec3d() : x(0), y(0), z(0){}
   Vec3d(double xin, double yin, double zin){
     x = xin;
     y = yin;
     z = zin;
   }
   Vec3d(double xin, double yin) : z(0){
     x = xin;
     y = yin;
   }
   Vec3d(double xin) : y(0), z(0){
     x = xin;
   }

   Vec3d(const Vec3d& orig) : x(orig.x), y(orig.y), z(orig.z){}//copy constructor


   friend Vec3d operator +(const Vec3d& a, const Vec3d& b){
     Vec3d ans;
     ans.x = a.x + b.x;
     ans.y = a.y + b.y;
     ans.z = a.z + b.z;
     return ans;
   }

   friend Vec3d operator -(const Vec3d& a, const Vec3d& b){
     Vec3d ans;
     ans.x = a.x - b.x;
     ans.y = a.y - b.y;
     ans.z = a.z - b.z;
     return ans;
   }

   friend Vec3d operator -(const Vec3d& b) {
     Vec3d ans;
     ans.x = -1*(b.x);
     ans.y = -1*(b.y);
     ans.z = -1*(b.z);
     return ans;
   }

   Vec3d operator =(const Vec3d& orig){
     x = orig.x;
     y = orig.y;
     z = orig.z;
     return *this;
   }

   friend ostream& operator <<(ostream& c, const Vec3d& v){
     c << "(" << v.x << ", "<< v.y << ", " << v.z << ")";
     return c;
   }

   double mag()const{
     return (sqrt(x*x+y*y+z*z));
   }

   double magSq()const{
     return (x*x+y*y+z*z);
   }

   double dist(const Vec3d a)const {
     return (sqrt(pow(x-a.x,2)+pow(y-a.y,2)+pow(z-a.z,2)));
   }

   double dot(const Vec3d a)const {
     return (x*a.x + y*a.y + z*a.z);
   }

   static double dot(Vec3d a, Vec3d b){
     return (a.x*b.x + a.y*b.y + a.z*b.z);
   }

   friend double dot (const Vec3d& a,const Vec3d& b);
   friend double dist(const Vec3d& a,const Vec3d& b);
 };

 double dot (const Vec3d& a,const Vec3d& b){
   double ans = (a.x * b.x) + (a.y*b.y) + (a.z * b.z);
   return ans;
 }

int main() {
       // use friend operators
     	const Vec3d a(1.0,2.5,3.5); // double precision!
     	const Vec3d b(2.0);         //(2,0,0)
     	const Vec3d c(2.0,3.5);     //(2,3.5,0)
     	const Vec3d d(); // d is a function that returns Vec3d
     	const Vec3d e;

       const Vec3d f = a + e;
       const Vec3d g = b - c; // d is not an object, pick a different one
       double x = dot(f,g); // regular function
       double y = Vec3d::dot(f,g); // static function
       double z = f.dot(g); // method
       const Vec3d h = -b;

       double dist = f.mag(); // square root of sum of square
       double dist2 = f.magSq(); // sum of square
       double dist3 = f.dist(g); // sqrt or sum of square of diff

       cout <<"a "<< a << '\n';
       cout <<"b "<< b << '\n';
       cout <<"c "<< c << '\n';
       cout <<"e "<< e << '\n';
       cout <<"f "<< f << '\n';
       cout <<"g "<< g << '\n';
       cout <<"h "<< h << '\n';
       cout <<"x "<< x << endl;
       cout <<"y "<< y << endl;
       cout <<"z "<< z << endl;
       cout <<"dist "<< dist << endl;
       cout <<"dist2 "<< dist2 << endl;
       cout <<"dist3 "<< dist3 << endl;
}
