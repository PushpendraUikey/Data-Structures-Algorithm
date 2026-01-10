#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Bad Boy
// https://codeforces.com/contest/1537/problem/B

int n, m, i, j;

void solve() {
    cin >> n >> m >> i >> j;

    // int diff1 = abs(n-i) + abs(m-j);
    // int diff2 = abs(n-1) + abs(m-j);
    // int diff3 = abs(n-i) + abs(m-1);
    // int diff4 = abs(n-1) + abs(m-1);

    // int maxi = max(diff1, diff2);
    // maxi = 2 * max(maxi, max(diff3, diff4));

    // cout << maxi << "\n";

    cout << 1 << " " << 1 << " " << n << " " << m << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
