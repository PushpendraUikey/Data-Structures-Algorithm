#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1632/B

void solve() {
    int n; cin >> n;
    int k = log2(n-1);
    int low = (1 << k);

    for (int i = 1; i < low; i++) {
        cout << i << ' ';
    }
    cout << 0 << ' ';
    for (int i = low; i < n; i++) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t-->0) {
        solve();
    }
}