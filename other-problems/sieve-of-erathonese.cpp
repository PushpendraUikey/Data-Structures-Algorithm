#include <bits/stdc++.h>
using namespace std;


int main(){
    int n ; cin >> n;

    // This is sieve of Eratosthenes: finds all the prime numbers between 1 to n;
    // vector<bool> prime(n+1, true);
    // for(int i=2; i<=n; i++){
    //     if(prime[i]==true){
    //         for(int j=2*i; j<=n; j+=i){
    //             prime[j] = false;
    //         }
    //     }
    // }

    // Below here is one more smaller optimization on the sieve of Eratosthenes
    // we'll start j = i*i, because any number below must have this form i*(i-1) or i*(i-2) or so on, so 
    // that means a smaller divisor. 
    vector<bool> prime(n+1, true);
    for(int i=2; i<=n; i++){
        if(prime[i]==true){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }


    for(int j=2; j<=n; j++){
        if(prime[j]){
            cout << j << ' ';
        }
    }
    cout << endl;
}