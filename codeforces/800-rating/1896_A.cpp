#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n; 
int arr[11];
void solve() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    if(arr[0] == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
