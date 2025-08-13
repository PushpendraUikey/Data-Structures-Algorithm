#include <bits/stdc++.h>
using namespace std;

// Naive Recursive Solution to the subset sum problem
int countSubset(int* arr, int n, int sum){
    if(n==0){
        return (sum==0)? 1:0;
    }

    return countSubset(arr, n-1, sum) + countSubset(arr, n-1, sum - arr[n-1]);
}

int countSubset_eff(int*arr, int n, int sum){
    int dp[n+1][sum+1];

    for(int i=0; i<=sum; i++) dp[0][i] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++){
        for(int s=1; s<=sum; s++){
            if(s < arr[i-1]){
                dp[i][s] = dp[i-1][s];
            }
            else{
                dp[i][s] = dp[i-1][s] + dp[i-1][s-arr[i-1]];
            }
        }
    }

    return dp[n][sum];
}