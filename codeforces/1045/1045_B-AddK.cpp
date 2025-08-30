#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1; cin >> tt;
    while(tt--){
        int n, k; cin >> n >> k;
        vector<long long> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];

        for(int i=0; i<n; i++){
            arr[i] = arr[i] + k * (arr[i]%(k+1));
        }

        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
}