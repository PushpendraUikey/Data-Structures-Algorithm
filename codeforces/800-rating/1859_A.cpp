#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
void solve() {
    cin >> n;
    vector<int> arr(n), divis(n,-1);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> b,c;
    for(int i=0; i<n; i++){
        bool found=false;
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(arr[j]%arr[i]==0){
                found = true;
                break;
            }
        }
        if(!found){
            c.push_back(arr[i]);
            for(int j=0;j<n;j++){
                if(i==j)continue;
                b.push_back(arr[j]);
            }
            break;
        }
    }

    if(b.empty()|| c.empty()){
        cout << -1 << "\n";
    }else{
        for(int i=0; i<b.size(); i++){
            cout << b[i] << ' ';
        } cout << "\n";
        for(int i=0; i<c.size(); i++){
            cout << c[i] << ' ';
        } cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
