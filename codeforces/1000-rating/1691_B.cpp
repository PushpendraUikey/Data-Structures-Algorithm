#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1691/B

int arr[100005];
void solve() {
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    if(n < 2) {
        cout << "-1\n";
        return;
    }
    if(arr[0] != arr[1] || arr[n-2] != arr[n-1]) {
        cout << "-1\n";
        return;
    }

    for(int i=1; i<n-1; i++) {
        if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
            cout << "-1\n";
            return;
        }
    }

    int j=0;
    int i=0;
    while(i<n) {
        while(i<n && arr[i] == arr[j]) i++;
        int size = (i-j);
        cout << i << ' ';
        for(int k=1; k < size; k++) {
            cout << (j+k) << ' ';
        }
        j = i;
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}