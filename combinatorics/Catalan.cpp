#include <bits/stdc++.h>
#include </home/pushpendra/DSA(Project)/combinatorics/binomialCoeff.cpp>
#define ll long long
using namespace std;

// Catalan number Cn is equal to summation(Ci*Cn-i-1) -> 0 to n-1
// Resembels with famous valid matching paranthesis problem.

ll __catalan(int n, vector<ll>&C){
    // base case n=0
    if(n==0) return 1;
    if(n<0) return 0; // not possible

    if(C[n] != -1) return C[n];
    ll _sum = 0;
    for(int i=0; i<n; i++){
        ll ci, cni;
        if(C[i] != -1) ci = C[i];
        else ci = __catalan(i, C);

        if(C[n-i-1] != -1) cni = C[n-i-1];
        else cni = __catalan(n-i-1, C);
        _sum += (ci*cni);
    }

    return C[n] = _sum;
}

// Here's the another very interesting formula for catalan numbers which is 1/(n+1) * 2nCn

int main(){
    int n; std::cout << "Give the number whose catalan is required: " ; cin >>n;
    std::vector<ll> C(n+1, -1);
    std::cout << "Catalan number corresponding to the given integer: " << __catalan(n, C) << endl;
    std::vector<vector<ll>> Val(2*n+1, vector<ll>(n+1, -1));
    ll ans = nCk(2*n, n, Val) / (n+1);
    std::cout << "Catalan number using binomial formula is: " << ans << endl;
}