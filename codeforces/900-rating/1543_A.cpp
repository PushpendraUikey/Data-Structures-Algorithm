#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Exciting Bets
// https://codeforces.com/contest/1543/problem/A

ull a, b;
void solve() {
    cin >> a >> b;

    if( a==b ) {
        cout << "0 0\n";
        return;
    }
    if( b > a ) swap(a, b);
    
    ull gcd = a - b;

    ull moves = min(b % gcd, gcd - (b%gcd));
    cout << gcd << " " << moves << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
