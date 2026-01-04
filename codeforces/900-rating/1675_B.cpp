#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Make it Increasing
// https://codeforces.com/contest/1675/problem/B
int n;
ull arr[31];
void solve() {
    cin >> n;
    for(int i=0;i<n; i++) {
        cin >> arr[i];
    }

    int oprn=0;
    for(int i=n-2; i>=0; i--) {
        while(arr[i] >= arr[i+1] && arr[i]>0) {
            arr[i] = arr[i] >> 1;
            oprn++;
        }
        if(arr[i] >= arr[i+1]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << oprn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
