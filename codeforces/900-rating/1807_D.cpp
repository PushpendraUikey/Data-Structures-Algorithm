#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Odd Queries
// https://codeforces.com/contest/1807/problem/D

int n, q;
ull arr[200005];
ull prefix_sum[200005];
void solve() {
    cin >> n >> q;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    prefix_sum[0] = 0;
    for(int i=1; i<=n; i++) {
        prefix_sum[i] = arr[i-1] + prefix_sum[i-1];
    }

    for(int i=0; i<q; i++) {
        int l, r;
        ull k;

        cin >> l >> r >> k;
        ull range = prefix_sum[r] - prefix_sum[l-1];
        ull value = prefix_sum[n] - range + (r-l+1)*k;

        if(value % 2 == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
