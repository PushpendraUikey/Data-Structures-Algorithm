#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1659/A

void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    string ans = "";

    // we need to distribute the resources evenly. that's the goal here. So we'll be dividing the r into b+1 buckets
    // how much each bucket will get r
    int distrib = r/(b+1);
    int remain = r%(b+1);

    string temp = "";
    for(int i=0; i<distrib; i++) temp += "R";
    for(int i=0; i<b; i++) {
        if(remain-->0){
            ans = ans + "R" + temp + "B";
        }else {
            ans = ans + temp + "B";
        }
    }
    ans += temp;

    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}