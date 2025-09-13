#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//  Burnside’s lemma can be used to count the number of combinations so that
//  only one representative is counted for each group of symmetric combinations

// The simple formula that can be used to calculate the burnside lemma is:
//     \Sigma(m^(__gcd(i, n))/n) [ i -> 0 to n-1 ]

// As an example, let us calculate the number of necklaces of n pearls, where
//  each pearl has m possible colors. Two necklaces are symmetric if they are similar
//  after rotating them.

ll gcd(ll a, ll b){if(a<b) return gcd(b,a); if(b==0) return a; return gcd(b, a%b);}
ll __power(ll a, ll k){
    ll __ans = 1;
    while(k>0){
        if(k&1){
            __ans *= a;
        }
        a *= a;
        k >>= 1;
    }
    return __ans;
}
// Necklace with 'n' pearls and 'm' possible colors for each pearl
ll __burnsideLemma(ll n, ll m){
    ll __num = 0;
    for(int i{0}; i<n; i++){
        __num += __power(m, gcd(n, i));
    }
    __num /= n;
    return __num;
}

int main(int argc, char* argv[]){
    if(argc != 3){
        perror("Invalid Arguments\n");
        exit(-1);
    }
    ll n = stoi(argv[1]);
    ll m = stoi(argv[2]);
    std::cout << "Number of necklace possible for given combination is: "<<__burnsideLemma(n, m) << "\n";
}