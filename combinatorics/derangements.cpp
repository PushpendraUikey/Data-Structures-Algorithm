#include <bits/stdc++.h>
#define ll long long
using namespace std;

// derangement of any number can be calculated using the simple recursion with memoization
// F(n) = (n-1)[F(n-1) + F(n-2)] for n > 2 
// F(2) = 1;
// F(1) = 0;


ll derange(int n, std::vector<ll>&D){
    if(n<=1) return 0;
    if(n==2) return 1;
    if(D[n] != -1) return D[n];

    ll ans = (ll)(n-1) * (derange(n-1, D) + derange(n-2, D));

    return D[n] = ans;
}
ll derangement(int n){
    std::vector<ll> D(n+1, -1);
    return derange(n, D);
}

int main(int argc, char*argv[]){
    int n; std::cout << "Give the number: "; cin >> n;

    std:: cout <<" Derangement of given number is : " << derangement(n) << endl;
}