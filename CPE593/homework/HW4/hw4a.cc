/*
 * Homework # : HW4A Grow Array
 * Due: 2/1/19
 * Name: Kirk Vasilas
 * Cite: Justin Trugman, Dave Lehman
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 */

 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <math.h>
 using namespace std;

 class Point {
 public:
     double x,y;
     Point(): x(0), y(0) { }
     Point(double x, double y) : x(x), y(y) { }
 };

 int numWordsInFile(string filename) {
     ifstream file(filename);
     string word;
     int wordCount = 0;

     while (file >> word) {
         wordCount++;
     }

     return wordCount;
 }
 void loadFileAsPointArray(string filename, Point* arr, int n) {
     ifstream file(filename);
     string fileString = string(
                                istreambuf_iterator<char>(file),
                                istreambuf_iterator<char>());

     // Convert string to an array of strings
     string strArr[n];
     int i = 0;
     stringstream ssin(fileString);
     while (ssin.good() && i < n){
         ssin >> strArr[i];
         ++i;
     };

     //Convert array of strings to array of ints
     int int_data[n];
     for (int i = 0; i < n; i++) {
         stringstream str_to_int(strArr[i]);
         str_to_int >> int_data[i];
     }

     //Convert array of ints to array of points
     for (int i = 0; i < (n/2); i++) {
         Point point(int_data[2*i], int_data[2*i+1]);
         arr[i] = point;
     }
 }
 void printArray(Point x[], int n) {
     for (int i = 0; i < (n/2); i++) {
         cout << x[i].x << ", " << x[i].y << endl;
     }
 }

 class GrowArray {
 private:
     Point* data;
     int capacity;
     int used;
     void grow() {
         const Point* old = data;
         data = new Point[capacity*2];
         for (int i = 0; i < used; i++)
             data[i] = old[i];
         capacity = capacity*2;
         // delete [] old;
     }
 public:
     GrowArray() {
         data = new Point[1];
         used = 0;
         capacity = 1;
     }
     GrowArray(int initialSize) {
         data = new Point[initialSize];
         capacity = initialSize;
         used = 0;
     } // set initial capacity
     void addEnd(Point v) {
         data[used] = v;
         used++;
         if (used == capacity) {
             grow();
         }
     }
     void addStart(int v) {
        /*
        int* old = data;
        data = new int[used+1];
        data[0] = v;
        for (int i = 0; i <= used; i++)
            data[i] = old[i - 1];
        used++;
        delete [] old;
        */
     }

     void removeEnd() {
         used--;
     }


     int size() const {
         return used;
     }// return how many elements in the list
     void print() const {
         for (int i = 0; i < used; i++) {
             cout << "(" << data[i].x << ", " << data[i].y << ") ";
         }
         cout << endl;
     }
 };

 class ConvexHull {
 private:
     GrowArray* grid;
     int numLists;
     double minx;
     double maxx;
     double miny;
     double maxy;
     void insert(int i, Point point) {
         grid[i].addEnd(point);
     }
     void printBox(int i) {
       grid[i].print();
     }
 public:
     ConvexHull(int size) {
         grid = new GrowArray[size*size];
         numLists = size;
     }
     void read(string filename) {
         // Load file as point array
         int numWords = numWordsInFile("convexhullpoints.dat");
         int numPoints = numWords / 2;
         Point data[numPoints];
         loadFileAsPointArray("convexhullpoints.dat", data, numWords);

         minx = data[0].x;
         maxx = data[0].x;
         miny = data[0].y;
         maxy = data[0].y;
         for (int i = 0; i < numWords/2; i++) {
           if(data[i].x > maxx)
             maxx = data[i].x;
           if(data[i].x < minx)
             minx = data[i].x;
           if(data[i].y > maxy)
             maxy = data[i].y;
           if(data[i].y < miny)
             miny = data[i].y;
         }

         double xSepVal = (maxx-minx)/numLists;
         double ySepVal = (maxy-miny)/numLists;

         for(int i = 0; i < numWords/2; i++) {
             Point pt(data[i].x, data[i].y);
             int xVal = floor((data[i].x - minx) / xSepVal);
             int yVal = floor((data[i].y - miny) / ySepVal);

             if(data[i].y == maxy)
               yVal = numLists-1;
             if (data[i].y == miny)
               yVal = 0;
             if (data[i].x == minx)
               xVal = 0;
             if (data[i].x == maxx)
               xVal = numLists-1;

             int index = (yVal*numLists)+xVal;
             insert(index, pt);
         }
     } // read file into convex hull grid
     void printAllListSizes() {
         cout << "-------------" << endl;
         cout << "PRINTING ALL LIST SIZES: " << endl;
         for (int i = 0; i < numLists*numLists; i++) {
             cout << i << ": " << grid[i].size() << " ";
             if ((i+1) % numLists == 0) {
                 cout << endl;
             }
         }
     }
     void printMinMax() {
       cout << "-------------" << endl;
       cout << "PRINTING MIN/MAX VALUES" << endl;
       cout << "Min X: " << minx << " | Max X: " << maxx << endl;
       cout << "Min Y: " << miny << " | Max Y: " << maxy << endl;
     }
     void printPerimeterClockWiseOrder() {
       cout << "-------------" << endl;
       cout << "PRINTING PERIMITER VALUES" << endl;
       for (int i = 0; i < numLists; i++) {
         cout << "Box " << i << ": ";
         printBox(i);
       }

       for (int i = 1; i < numLists-1; i++) {
         cout << "Box " << i*numLists << ": ";
         printBox(i*numLists);
         cout << "Box " << i*numLists+numLists-1 << ": " << endl;
       }

       for (int i = 1; i < numLists; i++) {
         cout << "Box " << (numLists-1)*(numLists) + i << ": ";
         printBox((numLists-1)*(numLists) + i);
       }
     }
     int size() {
       return numLists;
     }
 };

 int main() {
     ConvexHull ch(16); // create a 16x16 grid of GrowArray
     ch.read("convexhullpoints.dat");
     ch.printAllListSizes(); // tell us how many are in each list
     ch.printMinMax(); // print minx, maxx, miny, maxy
     ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4,p8,p12,p16..

 }
