#include <bits/stdc++.h>
using namespace std;

/*
You and your opponent are playing a game:
You have an array of integers (coins) arr[].
Each player picks either the first or last coin on their turn.
Both players play optimally — they want to maximize their own score.
You make the first move. Even number of coins exist.

Goal: Find the maximum value you can collect if both play optimally.
*/

int OptimalStrategy(int*arr, int i, int j, int sum){
    if(j==i+1){
        return max(arr[i], arr[j]);
    }

    return max(
        sum - OptimalStrategy(arr, i+1, j, sum-arr[i]),
        sum - OptimalStrategy(arr, i, j-1, sum-arr[j])
    );
}
int mainOptimalStrategy(int*arr, int n){
    int sum=0;
    for(int i=0; i<n; i++) sum += arr[i];
    return OptimalStrategy(arr, 0, n-1, sum);
}


// My best move = pick current value + minimum of what I may get after opponent's optimal move.
int OptimalStrategy_eff(int*arr, int i, int j){
    if(j==i+1){
        return max(arr[i], arr[j]);
    }
    return max(
        arr[i]+min(OptimalStrategy_eff(arr, i+2,j), OptimalStrategy_eff(arr,i+1,j-1)),
        arr[j]+min(OptimalStrategy_eff(arr,i, j-2), OptimalStrategy_eff(arr, i+1, j-1))
    );
}

// Optimal solution to the above problem using Tabulation approach
int OptimalStrategy_opt(int*arr, int n){
    int dp[n][n];
    // These are the returned value in the base case of Recursion
    for(int i=0; i<n-1; i++){
        dp[i][i+1] = max(arr[i], arr[i+1]);
    }

    for(int gap=3; gap < n; gap += 2){
        for(int i=0; i+gap<n; i++){
            int j = i+gap;
            dp[i][j] = max(arr[i]+min(dp[i+2][j], dp[i+1][j-1]), arr[j]+min(dp[i][j-2], dp[i+1][j-1]));
        }
    }

    return dp[0][n-1];
}


// Following works even when the length of array is not even.
class Solution {
    int solve(vector<int>&arr,vector<vector<int>>&dp, int i, int j){
        if(i>j) return dp[i][j] = 0;
        if(j==i+1) return dp[i][j] = max(arr[i], arr[j]);
        if(i==j) return dp[i][j] = arr[i];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = max(
            arr[i] + min(solve(arr, dp, i+2, j), solve(arr, dp, i+1, j-1)),
            arr[j] + min(solve(arr, dp, i, j-2), solve(arr, dp, i+1, j-1))
            );
    }
  public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(arr, dp, 0, n-1);
    }
};