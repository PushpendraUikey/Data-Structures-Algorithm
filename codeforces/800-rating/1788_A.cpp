#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Serval and Mocha's array
// https://codeforces.com/contest/1789/problem/A
int n;
int arr[1001];

void solve() {
    cin >> n;
    int two = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i] == 2) two++;
    }

    if(two % 2 != 0) {
        cout << -1 << "\n";
    }
    else {
        two /= 2;
        for(int i=0; i<n; i++) {
            if(arr[i] == 2) two--;
            if(two==0) {
                cout << i+1 << "\n";
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
