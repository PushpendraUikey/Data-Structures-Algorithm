#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1690/D

char arr[200005];
void solve() {
    int n, k; cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int white = 0;
    for(int i=0; i<k; i++) {
        if(arr[i] == 'W') white++;
    }
    if(white==0) { cout << "0\n"; return; }
    int minwhite = white;

    for(int i=k; i<n; i++){
        if(arr[i-k] == 'W') white--;
        if(arr[i] == 'W') white++;
        if(white==0) { cout << "0\n"; return; }
        if(white<minwhite) minwhite = white;
    }

    cout << minwhite << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}