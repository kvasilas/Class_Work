#include <algorithm>
#include <iostream>

using namespace std;

void permute1() {
    int x[] = {1,2,3,4};
    do {
        for (int i = 0; i < 4; i++) {
            cout << x[i] << '\t';
        }
        cout << '\n';
    } while(std::next_permutation(x, x+4));
}

void doit(char s[]){
    cout << s << '\n';
}

void permute(char s[], int n){
    cout << "permute " << n << '\n';
    if(n == 0){
        doit(s);
        return;
    }
    for (int i = 0; i <= n; i++) {
        swap(s[i], s[n]);
        permute(s, n-1);
        swap(s[i], s[n]);
    }
}

int main() {
    char s[] = "abc";
    permute(s, 2);
    return 0;
}
