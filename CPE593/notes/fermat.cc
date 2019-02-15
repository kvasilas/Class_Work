#include <iostream>
#include <cstdlib>
using namespace std;

int random(int a, int b){
    return a + rand() % (b-a+1);

}

powermod(uint64_t a, uint64_t n, uint64_t m){
    uint64_t prod = 1;
    while(n>0){
        if (n%2 != 0) {prod = (prod*a)%m;}
        a = (a*a)%m;
        n = n/2;
    }
    return prod;
}

bool fermat(uint64_t p, int k){
    for (int i = 0; i < k; i++) {
        uint64_t a = random(2, p-1);
        if (powermod(a, p-1, p) != 1) {
            return false;
        }
    return true;
    }
}

int main() {
    cout << fermat(561, 5) << '\n';
    cout << fermat(1000, 5) << '\n';
    cout << fermat(17, 5) << '\n';
}
