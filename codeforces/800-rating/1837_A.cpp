#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int k, x;
void solve() {
    cin >> x >> k;

    if(x%k != 0) {
        cout << "1\n" << x << "\n";
    }
    else{
        cout << "2\n" << x-1 << ' ' << 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
