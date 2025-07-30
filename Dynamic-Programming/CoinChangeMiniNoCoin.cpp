#include <bits/stdc++.h>
using namespace std;

/*
You are given an amount denoted by value. You are also given an array of coins. The array contains 
the denominations of the given coins. You need to find the minimum number of coins to make the 
change for value using the coins of given denominations. Also, keep in mind that you have infinite 
supply of the coins.
*/

class Solution {
    long long minicoin = 0;
    long long solve(int coins[], long long num, int n, int val, vector<vector<int>>&dp){
        if(val < 0) return 0;
        if(val == 0) {
            minicoin = min<long long>(num, minicoin);  // if valid solution exist the mininumber of coin taken
            return dp[n][val] = 1;
        }
        if(n==0) return 0;
        if( dp[n][val] != -1 ) return dp[n][val]; // next time we reach here it's always gonna take more
            // than or equal coins because the coins are sorted and we're going in backward direction
            // so no need to care for updating the minicoin!
        
        return dp[n][val] = (solve(coins, num+1, n, val-coins[n-1], dp) 
            + solve(coins, num, n-1, val, dp));
    }
  public:
    // Function to find the minimum number of coins to make the change
    // for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[], int n, int value) {
        
        vector<vector<int>> dp(n+1, vector<int>(value+1, -1));
        minicoin = LONG_MAX;
        sort(coins, coins+n);
        
        solve(coins, 0, n, value, dp);
        
        return minicoin == LONG_MAX ? -1 : minicoin;
    }
};