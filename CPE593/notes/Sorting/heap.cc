#include <iostream>
#include <fstream>
using namespace std;

void print_array(int array[], int len){
    for (int i = 0; i < len; i++) { cout << array[i] << '\t'; }
    cout << '\n';
}

void heapify(int arr[], int n, int i){
    int huge = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    //parent vs children
    if(l < n && arr[l] > arr[huge])
        huge = l;
    if (r < n && arr[r] > arr[huge])
        huge = r;

    // max isnt root
    if(huge != i){
        swap(arr[i], arr[huge]);
        heapify(arr, n, huge);
    }
}

int heap_sort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
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
