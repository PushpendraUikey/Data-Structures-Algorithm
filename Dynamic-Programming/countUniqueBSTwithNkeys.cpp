#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000009
// Given a number n, you have 1,2,3...,n keys available. How many distinct BSTs can you form

ll countUniqueBST(ll n){
    
    if(n==0 || n==1) return 1;
    if(n==2) return 2;

    ll res = 0;
    for(int i=1; i<=n; i++){
        res += countUniqueBST(i-1)*countUniqueBST(n-i);
    }

    return res;
}

// DP optimization
ll countUniqueBST_eff(ll n, vector<ll>&ans){
    if(n==0 || n==1) return ans[n] = 1;
    if(n==2) return ans[n] = 2;

    if(ans[n] != -1) return ans[n];
    ll res = 0; ll t1, t2;
    for(ll i=1; i<=n; i++){
        if(ans[i-1] != -1) t1=ans[i-1];
        else t1 = countUniqueBST_eff(i-1, ans);
        if(ans[n-i] != -1) t2=ans[n-i];
        else t2 = countUniqueBST_eff(n-i, ans);

        res = (res + (t1*t2)%mod)%mod;
    }

    return ans[n] = res%mod;
}

ll countUniqueBST_spaceEff(ll n){
    ll dp[n+1];
    dp[0] = 1;

    for(ll i=1; i<=n; i++){
        dp[i] = 0;
        for(ll j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main(int argc, char* argv[]){
    ll n; cout << "Give a num: "; cin >> n;
    vector<ll> vec(n+1, -1);
    cout << "Total number of BSTs are: " << countUniqueBST_eff(n, vec) << endl;
    
}