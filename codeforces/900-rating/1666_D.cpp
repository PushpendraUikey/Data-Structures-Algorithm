#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Deletive Editing
// https://codeforces.com/contest/1666/problem/D

string s, t;
void solve() {
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'A']++;
    }
    for (char c : t) {
        count[c - 'A']--;
    }

    for (int i=0; i<26; i++) {
        if(count[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    string ans = "";
    for (int i=0; i<n; i++) {
        if(count[s[i]-'A'] > 0) {
            count[s[i]-'A']--;
        }else{
            ans += s[i];
        }
    }

    if(ans == t) {
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
