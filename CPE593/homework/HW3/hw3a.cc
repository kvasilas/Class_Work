/*
 * Homework # : HW3A Insertion Sort
 * Due: 2/1/19
 * Name: Kirk Vasilas
 * Cite: Justin Trugman, Dave Lehman
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 */

#include <iostream>
#include <fstream>
using namespace std;

void print_array(int array[], int len){
    for (int i = 0; i < len; i++) { cout << array[i] << '\t'; }
    cout << '\n';
}

void insertion_sort(int array[], int length){
    for (int i = 1; i < length; i++) {
        for (int j = i; j >= 1; j--) {
            if(array[j] < array[j-1]) { swap(array[j], array[j-1]); }
            else{break;}
        }
    }
    print_array(array, length);
}

int main(){
   int len;
   ifstream file("hw3.dat");
   if(file.is_open()) {
       file >> len;
       int a[len];
       for (int i = 0; i < len; i++){ file >> a[i]; }
       cout << "Array Length = " << len << '\n';
       for (int i = 0; i < len; i++){ cout << a[i] << '\t'; }
       cout<<"\nArray after sorting:\n";
       insertion_sort(a, len);
   }
   return 0;
}
