#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXV = 400000;  // safe upper bound for values

void solve() {
    int n;
    ll y;
    cin >> n >> y;

    static ll freq[MAXV+1], pref[MAXV+1];
    fill(freq, freq+MAXV+1, 0);

    int maxA = 0;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        freq[v]++;
        maxA = max(maxA, v);
    }

    // prefix counts
    pref[0] = freq[0];
    for(int i = 1; i <= maxA; i++) 
        pref[i] = pref[i-1] + freq[i];

    ll ans = LLONG_MIN;

    // try all divisors x
    for(int x = 2; x <= maxA; x++) {
        ll profit = 0;
        for(int k = 1; (k-1)*x + 1 <= maxA; k++) {
            int l = (k-1)*x + 1;
            int r = min(k*x, maxA);

            ll blockCount = pref[r] - pref[l-1];
            if(blockCount == 0) continue;

            ll exactMultipleCount = (k*x <= maxA) ? freq[k*x] : 0;
            ll tagsNeeded = blockCount - exactMultipleCount;

            profit += 1LL * k * x * blockCount;
            profit -= y * tagsNeeded;
        }
        ans = max(ans, profit);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
