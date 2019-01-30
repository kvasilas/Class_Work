/*
 * Homework # : HW1a Eratosthenes
 * Due: 2/1/19
 * Name: Kirk Vasilas
 * Cite: Justin Trugman, Dave Lehman
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 */

 #include <iostream>
 #include <vector>
 #include <cmath>
 using namespace std;

 void eratosthenes (int n) {
    bool is_prime[n]; //store all values
    for (int i = 0; i<= sizeof(is_prime); i++){
        is_prime[i] = true;
    }
    
    for (int i = 2; i = sqrt(n); i++){ /*use sqrt because it steps down faster than /2 */
        if(is_prime[i] == true){
            for(int j = i*2; j <= n; j+=i){
                is_prime[j] = false;
            }
        }
    }
    
    for(int i = 2; i <= sizeof(is_prime); i++){
        if(is_prime[i] == true) {cout << i << '\t';}
    }
    cout << '\n';
 }


 int main (){
     eratosthenes(10);
 }
