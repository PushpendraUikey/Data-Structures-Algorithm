#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Balanced Round
// https://codeforces.com/contest/1850/problem/D

int n;
ull k;
ull arr[200005];
int rem = 0;
void solve() {
    cin >> n >> k;
    rem = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int max_balanced = 0;
    int prev = 0;
    for (int i=1; i<n; i++) {
        ull diff = arr[i] - arr[i-1];
        if(diff > k) {
            max_balanced = max(max_balanced, i - prev);
            prev = i;
        }
    }
    max_balanced = max(max_balanced, n - prev);
    cout << n - max_balanced << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
