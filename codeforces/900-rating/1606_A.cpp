#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// AB Balance
// https://codeforces.com/contest/1606/problem/A

string s;

void solve() {
    cin >> s;
    int len = s.length();

    if(s[0] == s[len-1]){
        cout << s << '\n';
    }else{
        s[0] = s[len-1];
        cout << s << '\n';
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
