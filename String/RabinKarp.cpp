#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

void rabinKarp(const string& txt, const string& pat){
    int n = txt.length();
    int m = pat.length();
    int d = m;
    int h = 1;
    for(int i=1; i<m; i++) h = (h*d)%mod;
    // hashes
    int p=0, t=0;
    for(int i=0; i<m; i++){
        p = ((p*d) + pat[i]) % mod;
        t = ((t*d) + txt[i]) % mod;
    }
    for(int i=0; i<=n-m; i++){
        if(p==t){
            int j=0;
            for( ; j<m; j++){
                if(pat[j] != txt[i+j]) break;
            }
            if(j==m) cout << "Pattern found at index: " << i << endl;
        }
        if(i<n-m){  // compute the rolling hash!
            t = ( (d*(t - txt[i]*h)) + txt[i+m] ) % mod;
            if(t < 0) t += mod;
        }
    }
}