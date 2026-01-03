#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int n;
int arr[1001];
void solve() {
    cin >> n;
    
    for(int i=0; i<n; i++) cin >> arr[i];
    
    int xr = 0;
    for(int i=0; i<n; i++) xr ^= arr[i];
    if(n%2==0){
        if(xr==0) cout << "1\n";
        else{
            cout << "-1\n";
        }
    }else{
        cout << xr << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
