#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n, a, b;
void solve() {
    cin >> n >> a >> b;
    if(n < a || n < b) {
        cout << "NO\n";
    }
    else {
        if( n==a && a == b) {
            cout << "YES\n";
        }
        else if( a+b <= n-2 ){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
