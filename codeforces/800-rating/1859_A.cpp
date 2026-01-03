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
    sort(arr.begin(), arr.end());

    vector<int> b, c;
    int i;
    b.push_back(arr[0]);
    for(i=1; i<n; i++){
        if(arr[i] == arr[0]){
            b.push_back(arr[i]);
        }else break;
    }
    for( ; i<n; i++){
        c.push_back(arr[i]);
    }

    if(b.empty()|| c.empty()){
        cout << -1 << "\n";
    }else{
        cout << b.size() << ' ' << c.size() << "\n";
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
