#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a, b;
void solve(){
    cin >> a >> b;

    if(a%2==1 && b%2==1) cout << (a*b+1) <<"\n";
    else if(a%2==0 && b%2==1){
        cout << -1 << "\n";
    }
    else if(a%2==0 && b%2==0){
        cout << (a*(b/2)+2) << "\n";
    }else{
        if(b%2==0 && b%4!=0) cout << -1 << "\n";
        else {
            cout << (a*(b/2)+2) << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}