#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Longest Divisors Interval
// https://codeforces.com/contest/1855/problem/B

ull n;
void solve() {
    cin >> n;

    for(int i=1; i<=n; i++) {
        if(n%i != 0) {
            cout << i-1 << "\n";
            return;
        }
    }
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
