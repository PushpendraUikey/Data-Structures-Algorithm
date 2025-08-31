#include <bits/stdc++.h>
using namespace std;

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<int> arr(n+1), dp(n+1, 0);
        deque<int> dq[n+1];
        for(int i=1; i<=n ; i++){
            cin >> arr[i];
            dp[i] = dp[i-1];
            dq[arr[i]].push_back(i);
            if(dq[arr[i]].size() > arr[i]) dq[arr[i]].pop_front();
            if(dq[arr[i]].size() == arr[i]) dp[i] = max(dp[i-1], dp[dq[arr[i]].front()-1]+arr[i]);
        }

        cout << dp[n] << "\n";
    }
}