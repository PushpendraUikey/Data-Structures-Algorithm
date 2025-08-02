#include <bits/stdc++.h>
using namespace std;

/*
Given a value V, if we want to make a change for V cents, and we have an infinite supply of each of 
C = { C1, C2, .., Cm} valued coins, what is the minimum number of coins to make the change? 
If it's not possible to make a change, print -1.
*/

int getMin(int coins[], int n, int val){
    if(val==0) return 0;

    int res = INT_MAX;
    for(int i=0; i<n; i++){
        if(coins[i] <= val){
            int sub_res = getMin(coins, n, val-coins[i]);
            if(sub_res != INT_MAX){
                res = min(res, sub_res+1);
            }
        }
    }
    return res;
}

// Tabulation based solution the above problem
int getMin(int coins[], int n, int val){
    int res[val+1];
    res[0] = 0;

    for(int i=0; i<=val; i++){
        res[i] = INT_MAX;
        for(int j=0; j<n; j++){
            int idx = i-coins[j];
            if( idx >= 0 && res[idx] != INT_MAX ){
                res[i] = min(res[i], res[idx]+1);
            }
        }
    }

    return res[val]==INT_MAX ? -1 : res[val];
}