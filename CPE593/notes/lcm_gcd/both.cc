lcm (int a, int b) {
    return (a*b)/gcd(a,b);
}

gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a,a);
}
