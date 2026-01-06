#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Mocha and Math
// https://codeforces.com/contest/1559/problem/A

int n;
int arr[101];
void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        sort(arr, arr+n);
        for(int i=0; i<n/2; i++) {
            int newval = arr[i] & arr[n-i-1];
            arr[i] = newval;
            arr[n-i-1] = newval;
        }
    }

    int max = *max_element(arr, arr+n);
    cout << max << '\n';
}

// Tutorial solution:
void tutorial_solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    int result = arr[0];
    for (int i=1; i<n; i++) {
        result &= arr[i];
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
