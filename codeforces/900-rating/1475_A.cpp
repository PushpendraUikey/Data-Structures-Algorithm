#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Odd Divisor
// https://codeforces.com/contest/1475/problem/A

ull n;

void solve() {
    cin >> n;

    if(n<3) {
        cout << "NO\n";
        return;
    }
    else if(n%2==1) {
        cout << "YES\n";
        return;
    }
    else {
        while(n%2==0) n/=2;
        if(n>1) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
