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
    }
    return true;
}

bool millerRabin(uint64_t p, int k){
    for (int i = 0; i < k; i++) {
        uint64_t a = random(2, p-2);
        int s;
        uint64_t d = p-1;
        uint64_t mask = 1;
        while(d & mask == 0){
            s++;
            d >>= 1;
        }
        uint64_t x = powermod(a, d, p);
        if(x == 1 || x == -1 )
            continue;
        for (int i = 0; i<s-1; i++){
            x = (x*x) % p;
            if (x == s-1)
                goto nextTrial;
        }
        return false;
    nextTrial:
    }
    return true;
}

int main() {
    cout << fermat(561, 5) << '\n';
    cout << fermat(1000, 5) << '\n';
    cout << fermat(17, 5) << '\n';
}
