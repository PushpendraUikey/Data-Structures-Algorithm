#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, x;
void solve() {
    cin >> n >> k >> x;

    if(x != 1) {
        cout << "YES\n";
        cout << n << "\n";
        for(int i = 0; i < n; i++) cout << "1 ";
        cout << "\n";
    }
    else {
        if(k==1) {
            cout << "NO\n";
            return;
        }
        if(n%2==1) {
            if(k>=3) {
                cout << "YES\n";
                cout << (n-3)/2 + 1 << "\n";
                cout << "3 ";
                for(int i=0; i< (n-3)/2; i++) cout << "2 ";
                cout << "\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "YES\n";
            cout << n/2 << "\n";
            for(int i=0; i < n/2; i++) cout << "2 ";
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
