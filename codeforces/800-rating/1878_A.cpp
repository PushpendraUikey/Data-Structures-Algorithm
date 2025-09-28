#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int ele;
void solve() {
    cin >> n >> k;
    bool present = false;
    for(int i=0; i<n; i++){
        cin >> ele;
        if(ele == k) present = true;
    }
    if(present) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
