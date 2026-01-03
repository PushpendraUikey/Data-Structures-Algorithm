#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull n, k;
void solve() {
    cin >> n >> k;
    
    if(n%2==0) cout << "YES\n";
    else{
        if(k%2==0) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
