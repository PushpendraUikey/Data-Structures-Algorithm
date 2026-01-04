#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Not dividing
// https://codeforces.com/contest/1794/problem/B

int n;
int arr[10005];
void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            arr[i]++;
        }
    }
    for(int i=1; i<n; i++) {
        if(arr[i] % arr[i-1] == 0) {
            arr[i]++;
        }
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
