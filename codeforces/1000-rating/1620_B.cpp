#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1620/B

void solve() {
    long long w, h; cin >> w >> h;
    long long max_area = -1;

    for(int j=0; j<4; j++) {
        int k;
        int first, last;
        cin >> k;
        cin >> first;
        for(int i=1; i<k; i++) cin >> last;

        long long base = last-first;
        if(j<2){
            max_area = max(max_area, base*h);
        }else{
            max_area = max(max_area, base*w);
        }
    }
    cout << max_area << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t-->0) {
        solve();
    }
}