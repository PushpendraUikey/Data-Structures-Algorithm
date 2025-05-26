/*
You are given all numbers between 1,2, ... ,n except one. 
Your task is to find the missing number.
*/
#include <bits/stdc++.h>
using namespace std;

// XOR of two same number is zero.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;    
    long long num=0;
    int i, k;
    for(i=1; i<n; i++){
        cin >> k;
        num ^= k;
    }
    for(i=1; i<=n; i++){
        num ^= i;
    }
    cout << num <<"\n";
}