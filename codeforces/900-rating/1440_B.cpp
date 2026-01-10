#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Sum of Medians
// https://codeforces.com/contest/1440/problem/B

int n, k;
int arr[200100];
void solve() {
    cin >>  k >> n;
    int len = n*k;
    for(int i=1;i<=len; i++) cin >> arr[i];

    ll x = (k+1)/2 - 1;
    x = k - x;
    ll z = n * k + 1;

    ll ans = 0;
    // int qu = (n+1)/2;
    // int idx = (qu-1)*k;
    // if(idx<0) idx = 0;
    // ull medsum = 0;

    while(n--){
        z-=x;
        if(z<=0) break;
        ans += arr[z];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
