#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Longest Divisors Interval
// https://codeforces.com/contest/1837/problem/B

int n;
string s;
void solve() {
    cin >> n >> s;

    int min_elem = 1;
    int left = 0;
    int right = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '<') {
            right++;
            min_elem = max(min_elem, right + 1);
            left = 0;
        } else {
            left++;
            min_elem = max(min_elem, left + 1);
            right = 0;
        }
    }
    cout << min_elem << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
