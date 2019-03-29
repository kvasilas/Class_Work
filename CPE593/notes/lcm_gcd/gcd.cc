int gcd(int a, int b){
    if (a==0){ return(a); }
    return gcd(b%a, a);
}
