#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
string x, s;
void solve() {
    cin >> n >> m;
    cin >> x >> s;
    for(int i=0; i<6; i++) {
        if( x.find(s) != string::npos ) {
            cout << i << "\n";
            return;
        }
        x = x + x;
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
