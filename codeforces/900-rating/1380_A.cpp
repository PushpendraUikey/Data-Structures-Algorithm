#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Three Indices
// https://codeforces.com/contest/1380/problem/A

int n;
int arr[1005];
void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];

    for(int i=2; i<n; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            cout << "YES\n";
            cout << i-1 << ' ' << i << ' ' << i+1 << "\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
