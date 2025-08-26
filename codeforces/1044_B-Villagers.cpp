#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> g(n);
        for (int i = 0; i < n; ++i) cin >> g[i];

        sort(g.begin(), g.end(), greater<long long>());
        long long ans = 0;
        for(int i=0; i<n; i+=2){
            ans += g[i];
        }
        cout << ans << "\n";
    }

    return 0;
}
