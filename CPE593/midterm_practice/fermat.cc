uint64_t powermod(uint64_t a, uint64_t n, uint64_t m){
    uint64_t prod = 1;
    while(n>0){
        if(n%2 != 0){prod = (prod*a)%m; }
        a = a*a%m;
        n = n/2;
    }
    return prod;
}

bool fermat(uint64_t p, int k){
    for (int i = 0; i < k; i++) {
        uint64_t a = random(2, p-1);
        if (powermod(a, p-1, p) != 1){
            return false;
        }
    }
    return true;
}
