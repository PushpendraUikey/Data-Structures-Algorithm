/*
Problem: https://cses.fi/problemset/task/1643/
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long * arr = new long long[n];
    int i;
    for(i=0; i<n; i++) cin >> arr[i];

    long long maxi = LLONG_MIN;
    long long sumsofar = 0;
    for(i=0; i<n; i++){
        sumsofar = max(sumsofar+arr[i], arr[i]);
        maxi = max(maxi, sumsofar);
    }
    cout << maxi << "\n";
    delete arr;
}