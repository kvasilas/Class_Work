/*
 * Hw1c
 * Kirk Vasilas
 *I pledge my honor that i have abided by the stevens honor code
*/
#include <iostream>
using namespace std;

int main()
{
    // sum numbers from 1-100
    // display as n(n+1/2) = sum
    // use a loop
    // prove that they are the same

    int i;
    int n = 0;
    int gsum = 0;  //sum using gauss
    int lsum = 0;  // sum using loop

    cout << "enter number to sum up to  ";
    cin >> n;

    // Gauss formula
    gsum = n*(n+1)/2;

    cout << "By Gauss formula the sum of the numbers from 0 to " << n << " is  equal to " << gsum << endl;


    // using a loop

    for(i =1; i <= n; i++) {
        lsum = lsum + i;
    }


    cout << "By Loop the sum of the numbers from 0 to " << n << " is  equal to " << lsum << endl;
    cout << gsum << " is equal to " << lsum << endl;

    return 0;

}
