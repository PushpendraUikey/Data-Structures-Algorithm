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

    int maxval = INT_MIN;

    for(int i=0; i<n; i++) {
        maxval = max(maxval, (arr[n-1] - arr[i]));
        maxval = max(maxval, (arr[i] - arr[0]));
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
