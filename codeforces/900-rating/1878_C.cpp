#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull n, k;
ull x;
void solve() {
    cin >> n >> k >> x;
    ull min_val = 0;
    ull max_val = 0;
    int temp = k;
    min_val = (k * (k+1)) / 2;
    max_val = (n * (n+1)) / 2 - ((n - k) * (n - k + 1)) / 2;

    if( x >= min_val && x <= max_val ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
