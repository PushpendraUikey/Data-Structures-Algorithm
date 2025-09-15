#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x;

void solve(){
    cin >> n;
    
    priority_queue<ll> pq;

    ll total = 0;
    for(ll i=0; i<n; i++){
        cin >> x;
        
        if(x%2==1) pq.push(x);
        else{
            total += x;
        }
    }
    if(pq.empty()){
        cout << 0 << "\n";
        return;
    }else{
        total += pq.top(); pq.pop();
        int size = pq.size();
        for(int i=0; i<size/2; i++){
            total += pq.top();
            pq.pop();
        }
    }

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