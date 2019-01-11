#include <iostream>
using namespace std;

class List {
private:
  int used;
  int capacity;
  int *list;
  void checkGrow(){
    if (used < capacity)
      return
    int *old = lsit;
    if (capacity == 0)
      capacity = 1;
    list = new int[capacity*2]
    for (int i = 0; i < capacity; i++) {
      list[i] = old[i];
    }
    delete [] old;
  }

public:
  List(int initial) : used(0), capacity(initial), list(new int[capacity]){}
  void add(int v){
    checkGrow();
    list[used++]  = v;
  }
  ~List(){
    delete [] list;
  }

  // Copy Constructor
  List(const List& orig):used(orig.used), capacity(orig.capacity), list(new int[capacity]) {
    for (int i = 0; i <= used; i++)
      list[i] = orig.list[i];
  }

  List& operator = (const List& orig){
    if(this != &orig){
      delete [] list;
      used = orig.used;
      capacity = orig.capacity;
      list = new int[capacity];
      for (int i = 0; i < used; i++)
        list[i] = orig.list[i];
    }
    return *this;
  }

//move Constructor only works in c++11
  List(List&& orig) : used(orig.used), capacity(orig.capacity), list(orig.list) { // EXTRA CREDIT
    orig.list = nullptr;
  }

  List BuildList(int a, int b){
    List ans(b-a+1);
    for (int i = 0; i <= b; i++) {
      ans.add(i)
    }
    return ans;
  }
};

int main(){
  List a(20);
  List b(30);
  a.add(5);
  b.add(5);
  List c = a; //copy Constructor
  b = a;
  c = c;
}
