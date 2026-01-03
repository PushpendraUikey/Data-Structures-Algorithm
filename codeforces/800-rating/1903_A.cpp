#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n, k;
int arr[101];
void solve() {
    int last=-1;
    bool sorted = true;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if( arr[i] >= last) {
            last = arr[i];
        }else{
            sorted = false;
        }
    }
    if( sorted ) {
        cout << "YES\n";
    }else{
        if( k == 1) {
            cout << "No\n";
        }
        else {
            cout << "YES\n";
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
