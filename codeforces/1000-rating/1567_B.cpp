#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1567/B

int computeXor(int n) {
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    return 0;
}
void solve() {
    int a, b; cin >> a >> b;
    int val = computeXor(a-1);

    if(val == b)
        cout << a << '\n';
    else {
        if((val ^ b) == a){
            cout << a + 2 << '\n';
        }else {
            cout << a + 1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt-->0) solve();
}