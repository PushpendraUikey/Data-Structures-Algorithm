#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int val;
int cnt;
int maxcnt = 0;
void solve() {
    cin >> n;
    cnt = 0;
    maxcnt = 0;

    for(int i=0; i<n; i++){
        cin >> val;
        if(val==1){
            cnt = 0;
        }else{
            cnt += 1;
            maxcnt = max(cnt, maxcnt);
        }
    }
    cout << maxcnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
