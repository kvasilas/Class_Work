/*
 * Homework # : Matrix
 * Due: 4/25/19
 * Name: Kirk Vasilas
 * Cite: Justin Trugman, Dave Lehman, Daniel Pinto
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 */

#include <iostream>
#include <vector>
using namespace std;


class Matrix{
private:
	int rows, cols;
	double* m;
	Matrix(int r, int c, char*) : rows(r), cols(c), m(new double[r*c]) {}
public:
	Matrix(int r, int c, double val = 0) : rows(r), cols(c), m(new double[rows*cols]) {
		for (int i = 0; i < rows*cols; i++)
			m[i] = val;
	}
	~Matrix() { delete [] m; }

	Matrix(const Matrix& orig);

	Matrix operator =(const Matrix& orig);

	Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
      orig.m = nullptr;
   }

   friend Matrix operator+(const Matrix& a, const Matrix& b) {
      if(a.rows != b.rows || a.cols != b.cols)
         throw "Bad size";
      Matrix ans(a.rows, a.cols);
      for(int i = 0; i < a.rows*a.cols; ++i)
         ans.m[i] = a.m[i] + b.m[i];

      return ans;
   }
      friend Matrix operator*(const Matrix& a, const Matrix &b) {
      if(a.cols != b.rows)
         throw "Size incorrect";

      Matrix ans(a.rows, b.cols);
      for(int k = 0; k < a.rows; k++) {
         for(int j = 0; j < b.cols; j++) {
            double dot = 0;
            for(int i = 0; i < a.cols; i++)
               dot += a(k,i) * b(i,j);
            ans(k,j) = dot;
         }
      }
      return ans;
   }
   friend Matrix operator-(const Matrix& a, const Matrix& b) {
      if(a.rows != b.rows || a.cols != b.cols)
         throw "Size incorrect";

      Matrix ans(a.rows, a.cols);
      for(int i = 0; i < a.rows*a.cols; ++i)
         ans.m[i] = a.m[i] - b.m[i];

      return ans;
   }

};

int main() {
  Matrix a(3,4,0.0);  // O(mn) = O(3*4)
  Matrix b(4,2,1.0); //O(n*p) = O(4*2);
  Matrix c = b; // make a copy O(np)
  Matrix d = a + a;  //O(mn)
  Matrix e = a * b;  //O(mnp)    O(n^3)
}
