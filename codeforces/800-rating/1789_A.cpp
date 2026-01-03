#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Serval and Mocha's array
// https://codeforces.com/contest/1789/problem/A
int n;
int arr[101];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int val = arr[0];

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(__gcd(arr[i], arr[j]) <= 2) {
                cout << "YES" << "\n";
                return;
            }
        }
    }
    cout << "NO" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
