#include <iostream>
#include <string>
using namespace std;

class string{
  private:
    char *s;
    int length;
    int used;
  public:
    string(const char s[]) {
      for (int i = 0; s[i] != '\0'; i++) {
        ;
        length = i;
        this->s = new char[length+1];
        strncpy(this->s, s, length+1);
        used = length;
      }
    }
    string(){
      s = nullptr;
      len = 0;
      used = 0;
    }
    string(int length) : length(length), used(0){
      s = new char[length];
    }
    ~string(){
      delete [] s;
    }
    string(const string& orig) : length(orig.length), used(orig.used) {
      s = new char[length];
      strcpy(s, orig.s);
    }
    //move constructure
    string(string&& orig) : length(orig.length), used(orig.used) {
      s = orig.s;
      orig.s = nullptr.
    }
    string& void operator =(const string& orig){
      if(this != &orig) {
        length = orig.length;
        used = orig.used;
        s = new char[length+1];
        strcpy(s, orig.s);
      }
      return *this;
    }

    bool operator == (const string& b)  {
      if(b.used != used){
        return false;
      }
      for (i = 0; i < used; i++) {
        if (s[i] != b.s[i]) {
          return false;
        }
      }
      return true;
    }

    string& operator +=(const string& b){
        if(used + b.used > length)
          grow(used+b.used);
        strcpy(s + used, b.s);
        used += b.used;
    }
};

void f(string s){

}

string& g( ){
  string("hornblower");
}


int main(){
  string s1("abc");
  string s2;
  string s3(1000);

  cout << s1 << '\n';
  string s4 = s1; //copy constructor
  string s5(s4);// same as above
  f(s5);
  if (s1 == s2) {
    cout << "same" << '\n';
  }
  s1 = s4;
  s1 += s4;
  cout << s1;
  string s6 = g();
  cout << s6;
}
