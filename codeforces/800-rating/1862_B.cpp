#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int arr[2*100005];
void solve() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int m=1;
    vector<int> brr;
    brr.push_back(arr[0]);

    for(int i=1; i<n; i++){
        if(arr[i-1] <= arr[i]){
            brr.push_back(arr[i]);
            m++;
        }else {
            brr.push_back(1);
            brr.push_back(arr[i]);
            m+=2;
        }
    }
    cout << m << "\n";
    for(int i=0; i<m; i++){
        cout << brr[i] << ' ';
    } cout << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
