#include <iostream>
#include <fstream>
using namespace std;

void print_array(int array[], int len){
    for (int i = 0; i < len; i++) { cout << array[i] << '\t'; }
    cout << '\n';
}

void heapify(iny arr[], int n, int i){

}

int heap_sort(int a[], int n){

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
        heap_sort(a, len);
        print_array(a, len);
    }
    return 0;
}
