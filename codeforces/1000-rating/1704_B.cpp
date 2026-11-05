#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1704/B

int arr[200005];
int b[200005];
int e[200005];
void solve() {
    int n, x;
    cin >> n >> x;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        b[i] = arr[i] - x;
        e[i] = arr[i] + x;
    }

    int cnt = 0;

    int overlapb = b[0];
    int overlape = e[0];

    for (int i=1; i<n; i++) {
        if(b[i] > overlape || e[i] < overlapb) {
            cnt++;
            overlapb = b[i];
            overlape = e[i];
        } else {
            overlapb = max(overlapb, b[i]);
            overlape = min(overlape, e[i]);
        }
    }
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt-->0) solve();
}