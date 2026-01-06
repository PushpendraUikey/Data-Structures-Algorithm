#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Odd Grasshopper
// https://codeforces.com/contest/1607/problem/B

// Need observation of pattern rather than simulating the jumps

ll x, n;
void solve() {
    cin >> x >> n;

    ll ans=0;
    if(n%4 == 1) ans = -n;
    else if(n%4 == 2) ans = 1;
    else if(n%4 == 3) ans = n + 1;
    else ans = 0;

    if(abs(x) % 2 == 0) cout << x + ans << "\n";
    else cout << x - ans << "\n";
    //     if(n<6){
    //         ll ans = x;
    //         for(ll i=1; i<=n; i++){
    //             if(abs(ans)%2 != 0){
    //                 ans += i;
    //             }else{
    //                 ans -= i;
    //             }
    //         }
    //         cout << ans << "\n";
    //         return;
    //     }

    //     ll term2 = (n-2)/4+1;
    //     ll term3 = (n-3)/4+1;
    //     ll term4 = (n-4)/4+1;
    //     ll term5 = (n-5)/4+1;

    //     ull sum2=0, sum3=0, sum4=0, sum5=0;

    //     if(term2>1)sum2 = (term2 * (2*2 + 4 * (term2-1))) / 2;
    //     if(term3>1)sum3 = (term3 * (2*3 + 4 * (term3-1))) / 2;
    //     if(term4>1)sum4 = (term4 * (2*4 + 4 * (term4-1))) / 2;
    //     if(term5>1)sum5 = (term5 * (2*5 + 4 * (term5-1))) / 2;
        
    // if(abs(x)%2 != 0) {
    //     ll ans = x + sum4 + sum5 - sum2 - sum3;
    //     if(n>0) ans += 1;
    //     cout << ans << "\n";
    // }else{
    //     ll ans = x - sum4 - sum5 + sum2 + sum3;
    //     if(n>0) ans -= 1;
    //     cout << ans << "\n";
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
