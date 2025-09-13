#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arr[200001];
int i, n;
void solve(){
    cin >> n;
    for(i=0; i<n; i++) cin >> arr[i];

    // for each pi the corresponding qi would be n+1-qi
    // in this way we'd maintain the constraint of pi+qi = n+1 
    // hence gcd of consecutive is n+1,

    for(i=0; i<n; i++) cout << (n+1 - arr[i]) << " ";
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