#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt-->0){
        int n; cin >> n;
        vector<ll> health(n+1), dp(n+1);
        for(int i=1;i<=n;i++) cin >> health[i];

        dp[0] = 0;
        dp[1] = health[1];
        for(int i=2; i<=n; i++){
            ll choice1 = dp[i-1] + health[i] - 1; // Single fall damage
            ll choice2 = dp[i-2] + health[i-1] + max<ll>(0ll, health[i]-(i-1));

            dp[i] = min(choice1, choice2);
        }
        cout << dp[n] << "\n";
    }
}