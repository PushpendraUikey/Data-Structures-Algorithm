#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x;
int arr[41];
int prefix[41];
void solve(){
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(i==0) prefix[i] = arr[i];
        else prefix[i] = arr[i] + prefix[i-1];
    }
    
    bool found = false;
    for(int j=0; j<n-2; j++){
        ll s1, s2, s3;
        s1 = prefix[j]%3;
        for(int i=j+1; i<n-1; i++){
            s2 = (prefix[i]-prefix[j])%3;
            s3 = (prefix[n-1] - prefix[i])%3;

            if(s1==s2 && s2==s3){
                cout << j + 1 << ' ' << i+1 << endl;
                found = true; break;
            }else if(s1 != s2 && s1!=s3 && s2!=s3){
                cout << j+1 << ' ' << i+1 << endl;
                found = true; break;
            }
        }
        if(found) break;
    }

    if(!found){
        cout << 0 << ' ' << 0 << "\n";
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