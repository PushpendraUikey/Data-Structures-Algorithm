#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Binomial coefficient can be calculated using recurence relation, efficiently(little bit)

int cnt=0;
ll nCk(int n, int k, vector<vector<ll>>&val){      // programmer's responsibility to ensure n>=k
    cnt++;
    // here comes the base case
    if(n==k || k==0) return 1;  // nCn & nC0 both are equal to 1.
    if(val[n][k] != -1) return val[n][k];

    return val[n][k] = (nCk(n-1, k-1, val) + nCk(n-1, k, val));
}

// bcz I'm calling this function in Catalan
// int main(){
//     int n, k; cin >> n >> k;
//     vector<vector<ll>> val(n+1, vector<ll>(k+1, -1));
//     std::cout << nCk(n, k, val) << " : with the number of calls to recursion: " << cnt << endl;
// }