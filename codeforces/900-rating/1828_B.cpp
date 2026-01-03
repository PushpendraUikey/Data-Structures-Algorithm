#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Permutation Swap
// https://codeforces.com/contest/1828/problem/B

int n;
int arr[200005];
void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++) {
        arr[i] = abs(arr[i] - (i+1));
    }

    int gcd_all = 0;
    for (int i=0; i<n; i++) {
        gcd_all = __gcd(gcd_all, arr[i]);
    }

    cout << gcd_all << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
