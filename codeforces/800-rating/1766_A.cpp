#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n;
ull x;
void solve() {
    cin >> n;
    x=0;
    if(n <= 10) {
        cout << n << "\n";
    }
    else if (n <= 100) {
        cout << 10 + n/10 - 1 << "\n";
    }
    else if (n <= 1000) {
        cout << 19 + n/100 - 1 << "\n";
    }
    else if (n <= 10000) {
        cout << 28 + n/1000 - 1 << "\n";
    }
    else if (n <= 100000) {
        cout << 37 + n/10000 - 1 << "\n";
    }
    else {
        cout << 46 + n/100000 - 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
