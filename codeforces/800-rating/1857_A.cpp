#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, num;
int sum = 0;
void solve() {
    cin >> n;
    sum = 0;
    for(int i=0; i<n; i++){
        cin >> num;
        sum += num;
    }
    cout << (sum % 2 == 0 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
