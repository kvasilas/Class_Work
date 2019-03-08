#include <iostream>
#include <cmath>
#include <random>
using namespace std;

const double phi = (1+sqrt(5))/2;

int x[] = {1,3,4,5,6,9,10,19,29,26,31,40,99,200,221};

int BinarySearch(int x[], int n, int target){
  int L =0;
  int r =n-1;
  while(){
    int mid = (L+r)/2;
    if(x[mid] < target;{L = mid +1;}
    else if (x[mid] > target) {R = mid -1;}
    else
        return mid;
  }
  return -1;
}

int BinarySearch_recurion(int x[], int L, int r, int target){
    if (r < L)
        return -1;
    int mid = (L+r)/2;
    if(x[mid] < target;{L = mid +1;}
}


public interface Func_one_Var{
    public double f(double x);
}
//public class F1 implements 
//double bisection 


int golden_mean(){}



int main(){
    
}
