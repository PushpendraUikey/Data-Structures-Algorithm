#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

int n, x;
int arr[101];
int brr[101];
int dp[101][2];

void solve(){
    cin >> n;
    
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) cin >> brr[i];

    ll ans = 2;

    for(int i=1; i<n; i++){
        if(min(arr[i], brr[i]) >= max(arr[i-1],brr[i-1])) {
            ans *= 2;
            ans %= mod;
        }
    }

    cout << ans << "\n";
    // dp[n-1][0] = 1; dp[n-1][1] = 1;

    // for(int i=n-2; i>=0; i--){

    //     // When ith and i+1th index is not swapped 
    //     if(arr[i] <= arr[i+1] && brr[i] <= brr[i+1]){
    //         dp[i][0] = dp[i+1][0];
    //     }
    //     // when ith index is not swapped but i+1th index is swapped.
    //     if(arr[i] <= brr[i+1] && brr[i] <= arr[i+1]){
    //         dp[i][0] = (dp[i][0] + dp[i+1][1])%mod;
    //     }

    //     // When ith index is swappd but i+1th not
    //     if(brr[i] <= arr[i+1] && arr[i] <= brr[i+1]){
    //         dp[i][1] = dp[i+1][0];
    //     }
        
    //     // when ith and i+1th both index are swapped
    //     if(brr[i] <= brr[i+1] &&  arr[i] <= arr[i+1]){
    //         dp[i][1] = (dp[i][1] + dp[i+1][1])%mod;
    //     }
    // }
    
    // cout << (dp[0][0]+dp[0][1])%mod << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}