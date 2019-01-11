#include <fstream>

class PostScript {
  private:
    int x, y;
  public:
    PostScript(){/*construct me */}

};

class Circle: public PostScript {
  private:
    int rad;
  public:
    Circle(int x, int y, int r) : x(x), y(y), rad(r){
      //file read
      //assign variables
     }
    void drawCircle(){
      std::cout << "bs" << x << y << r << '\n';
    }
};

class Rect: public PostScript {
  private:
    int width, height;
  public:
    Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h){
      //file read
      //assign variables
    }
    void drawRect(){
      std::cout << "postscript words" << x << y << w << h << "stroke" << '\n';
    }
    void fillRect(){
      cout << "postscript words" << x << y << w << h << "fill" <<  '\n';
    }
};

class Triangle: public PostScript{
  private:
    int x2, y2, x3, y3;
  public:
    Triangle(int x, int y, int x2, int y2, int x3, int y3) :  x(x), y(y),  x2(x2), y2(y2), x3(x3), y3(y3){}
    void drawTriangle(){
      cout << "postscript words" << x << y << x2 << y2 << x3 << y3 << "stroke" << '\n';
    }
    void fillTriangle(){
      cout << "postscript words" << x << y << x2 << y2 << x3 << y3 << "fill" << '\n';
    }
};
