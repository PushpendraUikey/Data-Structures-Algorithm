#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// 01 Game
// https://codeforces.com/contest/1373/problem/B

string s;

void solve() {
    cin >> s;

    int cnt0=0, cnt1=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '1') cnt1++;
        else cnt0++;
    }

    if(min(cnt0, cnt1)%2 != 0) cout << "DA\n";
    else cout << "NET\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
