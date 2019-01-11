/*
	Make the following main work by writing a class Complex.

  * Hw3a - Complex
  * Kirk Vasilas
  * Collaborators - Christopher Keenan
  *I pledge my honor that i have abided by the stevens honor code

  Notice that since objects are const, you will have to promise not to change them
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

		void print() const{//display output in terms of R+Ii
			if (imag <=0) {
        cout << real << imag << "i" << endl;
      }
      else{
      cout << real << "+" << imag << "i" << endl;
      }
		}

		Complex add(Complex right) const {//.add function
			return Complex (this->real + right.real, this->imag + right.imag);

		}

		Complex operator +(Complex right) const {//+ operator
			return Complex(this->real + right.real, this->imag + right.imag);
		}

		Complex operator -() const {//- negate
			return Complex(-this->real, -this->imag);

		}

};



int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using the first syntax we discussed
	c.print(); // should print the following to cout: (1.5,2.0)
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	Complex e = -d;
  e.print();
}
