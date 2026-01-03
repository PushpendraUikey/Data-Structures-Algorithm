#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int n;
string s;
void solve() {
    cin >> n >> s;
    int b=0, e=n-1;
    int ans=0;

    while(b<e){
        if(s[b] != s[e]){
            ans++;
        }
        else break;
        b++;
        e--;
    }
    ans *= 2;
    cout << (n-ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
