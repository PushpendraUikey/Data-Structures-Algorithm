#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, x, y;

void solve(){
    cin >> n >> m;
    
    ll currside = 0;
    ll currtime=0;
    ll total = 0;
    for(ll i=0; i<n; i++){
        cin >> x >> y;
        if(y==currside){
            total += (x-currtime);
            if((x-currtime)%2!=0){
                total--;
            }
        }else{
            total += (x-currtime);
            if((x-currtime)%2==0){
                total--;
            }
            currside = y;
        }
        currtime = x;
    }
    total += (m-currtime);
    cout << total << "\n";
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}