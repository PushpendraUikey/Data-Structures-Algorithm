#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int x;
void solve() {
    cin >> n;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        cin >> x;
        mp[x]++;
    }
    
    if(mp.size()>2){
        cout << "NO\n";
    }else{
        if(mp.size()==2){
            int first = -1, second = -1;
            for(auto [key, val] : mp){
                if(first==-1) first = val;
                else second = val;
            }

            if(abs(first - second) > 1) cout << "NO\n";
            else cout << "YES\n";
        }else{
            cout << "YES\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
