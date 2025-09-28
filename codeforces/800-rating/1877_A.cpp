#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
ll efficiency = 0;
ll ele = 0;
void solve() {
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> ele;
        efficiency += ele;
    }
    cout << -efficiency << "\n";
    efficiency = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
