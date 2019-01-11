#include <iostream>
using namespace std;

class A{ //object oriented: parent  c++:base class
private:
public:
  void f() {cout << "A ";}

};

class B: public A{ // kind of a, derived fro a
private:
public:
  void f() {cout << "B ";}
};

class C{ // 8 times bigger because its virtual
private:
public:
  virtual void f() {cout << "c ";}
};

class D: public C{
private:
public:
  void f() {cout << "d ";}
};

class E{ // 8 times bigger because its virtual
private:
public:
  virtual void f() = 0; //pure virtual
};

class F: public E{
private:
public:
  void f() {cout << "f ";}
};

class G: public E{
private:
public:
  void f() {cout << "g ";}
};


int main(){
  A a1;
  a1.f();//A::f
  B b1;
  b1.f();//B::f
  b1.A::f();//b calls the f that belongs to a

  A* p;//pointer of A
  p = &a1;
  p->f();//A::f
  p = &b1;
  p->f();//A::f not B::f because p points to class A [line 36]

  C c1;
  c1.f();//C::f
  D d1;
  d1.f();//D::f
  C* q = &c1;
  q->f(); //C::f()
  q = &d1;
  q->f();//D::f because it is virtual

  cout <<"   A=" << sizeof(A) << "   C=" << sizeof(C) << endl;

  //E e1; //abstract class and cannot be made
  E e2(); //retrns e
  E*p2; // pointer so its good
  // p2 = new E // cannot instantiate E
  p2 = new F(); // must be set to child of E, if not crossing types
  p2-> f();//F::f
  delete p2; //will leak
  p2 = new G(); // must be set to child of E, if not crossing types
  p2-> f();//G::f
  delete p2;


}
