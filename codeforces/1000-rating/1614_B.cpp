#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1614/B

void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n+1);
    priority_queue<pair<int, int>> pq;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        pq.push({arr[i], i});
    }
    uint64_t totalcost = 0;
    int i = 1;
    while(!pq.empty()){
        auto [a1, indx1] = pq.top(); pq.pop();
        arr[indx1] = i;
        totalcost += 2LL * a1 * i;
        if(pq.empty()) break;
        auto [a2, indx2] = pq.top(); pq.pop();
        arr[indx2] = -i;
        totalcost += 2LL * a2 * i;
        i++;
    }

    arr[0] = 0;
    cout << totalcost << '\n';
    for(int i=0; i<=n; i++) {
        cout << arr[i] << ' ';
    }   cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt-->0) solve();
}