#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int arr[501];
void solve() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int diff=INT_MAX;
    for(int i=1; i<n; i++){
        diff = min(diff, arr[i]-arr[i-1]);
    }
    if(diff<0 || diff == INT_MAX){
        cout << 0 << "\n";
    } else{
        cout << (diff+2)/2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
