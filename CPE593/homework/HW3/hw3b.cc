/*
 * Homework # : HW3B Quick Sort
 * Due: 2/1/19
 * Name: Kirk Vasilas
 * Collaborators: Justin Trugman, Dave Lehman
 * Cite: https://www.thecrazyprogrammer.com/2016/11/program-for-quick-sort-c.html
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 */

#include <iostream>
#include <fstream>
using namespace std;

void quick_sort(int[],int,int);
int partition(int[],int,int);

void quick_sort(int a[],int l,int u){
    int j;
    if(l<u){
        j = partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition(int a[],int l,int u){
    int v,i,j,temp;
    v = a[l];
    i = l;
    j = u+1;
    do{
        do
            i++;
        while(a[i]<v&&i<=u);
        do
            j--;
        while(v<a[j]);
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    while(i<j);
    a[l]=a[j];
    a[j]=v;
    return(j);
}

int main(){
   int n;
   ifstream file("hw3.dat");
   if(file.is_open()) {
       file >> n;
       int a[n];
       for (int i = 0; i < n; i++){
           file >> a[i];
       }
       cout << n << '\n';
       for (int i = 0; i < n; i++){
           cout << a[i] << '\t';
       }
       quick_sort(a,0,n-1);
       cout<<"\nArray after sorting:\n";

       for(int i=0;i<n;i++)
           cout << a[i] << '\t';
   }
    return 0;
}
