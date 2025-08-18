#include <bits/stdc++.h>
using namespace std;

/*
In this problem we need to figure out the minimum number of multiplication we need to 
multiply the chain of matrix.

Given the dimension of a sequence of matrices in an array arr[], where the dimension of the 
ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply 
these matrices together such that the total number of element multiplications is minimum.
*/

int mChain(int*arr, int i, int j){
    if(i+1==j) return 0;

    int res = INT_MAX;
    for(int k=i+1; k<j; k++){
        res = min(res, mChain(arr, i, k)+mChain(arr,k, j) + arr[i]*arr[k]*arr[j]);
    }
    return res;
}

// memoized solution!!!
int mChain(int*arr, int i, int j, int**dp){
    if(i+1==j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int res = INT_MAX;
    for(int k=i+1; k<j; k++){
        res = min(res, mChain(arr, i, k)+mChain(arr,k, j) + arr[i]*arr[k]*arr[j]);
    }
    return dp[i][j] = res;
}

// Tabulation based solution!
int mChain_opt(int*arr, int n){
    int dp[n][n];
    for(int i=0; i<n-1; i++){
        dp[i][i+1] = 0;
    }

    for(int gap = 2; gap < n; gap++){
        for(int i=0; i+gap<n; i++){
            int j = i+gap;
            dp[i][j] = INT_MAX;
            for(int k=i+1; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }

    return dp[0][n-1];
}