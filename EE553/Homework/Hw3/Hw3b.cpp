/*
	Make the following main work by writing a class Complex.
	In this second version you will overload operator << and use the friend
  syntax

  * Hw3b - Complex2
  * Kirk Vasilas
  * Collaborators - Christopher Keenan
  *I pledge my honor that i have abided by the stevens honor code
 */

 #include <iostream>
 #include <string>
 #include <cmath>
 using namespace std;

class Complex {
	private:
    double real, imag;

  public:

    Complex(double realNum, double imaginaryNum){//define numbers
			real = realNum;
			imag = imaginaryNum;
		}

    friend ostream& operator <<(ostream& s, Complex c);
    friend Complex operator +(Complex left, Complex right);
    friend Complex operator -(Complex d);

};

ostream& operator <<(ostream& s, Complex c) {
  if (c.imag <=0 ) {
    s << c.real << c.imag << "i";
  }
  else {
  s << c.real << "+" << c.imag << "i";
  }
  return s;
}

Complex operator +(Complex left, Complex right) {
  return Complex(left.real + right.real, left.imag + right.imag);
}

Complex operator -(Complex d) {
  return Complex(-d.real, -d.imag);
}

int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using friend
	Complex d = -c; // use friend
	cout << c << '\t' << d << '\n';
}
