#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int count =100000;
    int array[count];
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; i++) {
        array[i] = i;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count();
}
