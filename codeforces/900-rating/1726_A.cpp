#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Mainak and Array
// https://codeforces.com/contest/1726/problem/A

int n;
int arr[2005];
void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int maxval = arr[n-1] - arr[0];

    for(int i=1; i<n; i++) {
        maxval = max(maxval, (arr[n-1] - arr[i]));
        maxval = max(maxval, (arr[i] - arr[0]));
        maxval = max(maxval, (arr[i-1] - arr[i]));  // Order matters!
    }
    cout << maxval;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
