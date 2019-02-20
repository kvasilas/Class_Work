#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void print_array(int array[], int len){
    for (int i = 0; i < len; i++) { cout << array[i] << '\t'; }
    cout << '\n';
}

void merge(int array[], int l, int m, int r){
    int i, j, k;
    int n1 = m;
    int n2 = r - m;
    int Left[n1], Right[n2];
    for (i = 0; i < n1; i++) {
        Left[i] = array[1+i];
    }
    for(i = 0; i < n2; i++){
        Right[i] = array[m+1+i];
    }
    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2) {
        if(Left[i] <= Right[j]){
            array[k] = Left[i];
            i++;
        }
        else{
            array[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = Right[j];
        j++;
        k++;
    }

}

void merge_sort(int array[], int l, int r){
    if (l < r) {
        int mid = l+(r-1)/2;
        merge_sort(array, l, mid);
        merge_sort(array, mid+1, r);
        merge(array, 1, mid, r);
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
       print_array(a, len);
       cout << "\nArray after sorting:\n";
       merge_sort(a, 0, len-1);
       print_array(a, len);
   }
   return 0;
}
