//Bubble sorting algorithm
#include <iostream>
using namespace std;

void bubble(int a[], int n){
    for (int i = 0; i < n-1; i++) {
        bool sorted = true;
        for (int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                sorted = false;
            }
        if(sorted)
            return;
        }
    }
}
