//Instertion sort

#include <iostream>
#include <fstream>
using namespace std;

void insertion_sort(int array[], int length){
    for (int i = 1; i < length; i++) {
        for (int j = i; j >= 1; j--) {
            if(array[j] < array[j-1]) { swap(array[j], array[j-1]); }
            else{break;}
        }
    }
    return array;
}



int main(){
   int len;
   ifstream file("hw3.dat");
   if(file.is_open()) {
       file >> len;
       int a[n];
       for (int i = 0; i < len; i++){ file >> a[i]; }
       cout << "Array Length = " << len << '\n';
       for (int i = 0; i < len; i++){ cout << a[i] << '\t'; }
       a = insertion_sort(a, len);
       cout<<"\nArray after sorting:\n";
       for(int i = 0; i < len; i++)
           cout << a[i] << '\t';
   }
   return 0;
}
