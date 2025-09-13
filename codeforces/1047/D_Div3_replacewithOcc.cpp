#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, i;
int arr[200001];
void solve(){
    cin >> n;
    unordered_map<int, int> mp, tmp;
    for(i=0; i<n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    bool cond = false;
    
    for(const auto& [key, val]: mp){
        if((val % key) != 0){
            cond = true;
        }
    }
    if(cond){
        cout << -1 << "\n";
        return;
    }

    // for(auto& [key, val]: mp){
    //     if(key != 1){
    //         val = temp--;
    //     }
    // }
    int temp = 1;
    for(i=0; i<n; i++){
        if(mp[arr[i]]%arr[i]==0){
            tmp[arr[i]] = temp;
            cout << temp++ << " ";
        }else{
            cout << tmp[arr[i]] << " ";
        }
        mp[arr[i]]--;
        // if(arr[i]==1){
        //     cout << temp-- << " ";
        // }else{
        //     cout << mp[arr[i]] << " ";
        // }
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}