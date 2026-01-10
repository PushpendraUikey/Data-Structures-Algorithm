#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Multiply by 2, divide by 6
// https://codeforces.com/contest/1374/problem/B

ull n;
void solve() {
    cin >> n;
    if(n==1) {
        cout << 0 << "\n";
        return;
    }
    if(n%2==0 || n%3==0) {
        ull tn = n;
        int cnt2 = 0;
        int cnt3 = 0;
        while(tn%2==0){
            tn /= 2;
            cnt2++;
        }
        while(tn%3==0){
            tn /= 3;
            cnt3++;
        }
        //cout << tn << ' ' << cnt2 << ' ' << cnt3 << "\n";
        if(tn>1 || cnt2 > cnt3){
            cout << "-1\n";
        }else{
            int ans = 2*cnt3 - cnt2;
            cout << ans << "\n";
        }
    }
    else{
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
