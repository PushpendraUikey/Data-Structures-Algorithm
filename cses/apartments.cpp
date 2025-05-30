/*
Problem: https://cses.fi/problemset/task/1084
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force algorithm.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, i, cnt=0;
    cin >> n >> m >> k;

    vector<int> arr(n);
    vector<int> dpt(m);
    for( i=0; i<n; i++) cin >> arr[i];
    for( i=0; i<m; i++) cin >> dpt[i];

    for(auto& e: arr){
        for(i=0; i<m; i++){
            if(dpt[i] != -1 && dpt[i]-k <= e && dpt[i]+k >= e){
                cnt++;
                dpt[i]=-1;
                break;
            }
        }
    }

    cout << cnt << "\n";
}