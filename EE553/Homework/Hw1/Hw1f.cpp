/*
 * Hw1f
 * Kirk Vasilas
 * Collaborators - Christopher Keenan
 *I pledge my honor that i have abided by the stevens honor code
*/


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  float i = 0.0;
  float d = 0.0;
  float n = 0.0;
  float sumup = 0.0;
  float sumdwn = 0.0;

  cout << "Please enter a number " << endl;
  cin >> n;

  // sum 1/1^2 + 1/2^2... 1/n^2
  for (i = 1.0; i <= n; i=i+1.0) {
    sumup = sumup + 1/(i*i);
  }

cout << "sum of 1/1^2 + 1/2^2... 1/" << n << "^2 = " << sumup << endl;
cout << "[at 4100 the sum calculated stops increasing with a value of 1.64473]"<< endl;
cout << " " << endl;

cout << "Counting up the value is " << sqrt(6*sumup) << endl;

// sum 1/n^2 + 1/n-1^2... 1/1^2
for (d = n; d >= 1.0; d = d - 1.0) {
  sumdwn = sumdwn + 1/(d*d);
}
cout << "Counting down the value is " << sqrt(6*sumdwn) << endl;

  return 1;
}
