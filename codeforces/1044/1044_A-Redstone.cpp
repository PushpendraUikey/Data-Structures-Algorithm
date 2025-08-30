#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    int n;
    while(t-->0){
        cin >> n;
        unordered_map<int, bool> mp;
        bool isdup=false;
        int x;
        while(n-->0){
            cin >> x;
            if(mp[x]==true) isdup = true;
            mp[x] = true;
        }
        if(isdup) cout << "Yes\n";
        else cout << "No\n";
    }
}