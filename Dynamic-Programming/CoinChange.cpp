#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll countWays(const vector<int>&coins, ll sum, int n){
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(n == 0) return 0;
    return (countWays(coins, sum-coins[n-1], n) + countWays(coins, sum, n-1));
    // We have here infinte supply of coins hence the last parameter isn't changed even if included it
}

ll countWays_DP(const vector<int>&coins, int sum, int n){
    int dp[n+1][sum+1];

    for(int i=0; i<=n ; i++){
        dp[i][0] = 1;
    }
    for(int j=0; j<= sum ; j++){
        dp[0][sum] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum ; j++){
            dp[i][j] = dp[i-1][j];
            if(coins[i-1] <= j){
                dp[i][j] += dp[i][j-coins[i-1]];
            }
        }
    }

    return dp[n][sum];
}


/*
Given a positive integer n, the task is to find the number of different ways in which n can be written 
as a sum of two or more positive integers. Return the answer with the modulo 10^9+7.
*/
#define mod 1000000007
class Solution {
  public:
    int countWays(int n) {
        vector<vector<int>> dp(n, vector<int>(n+1,0));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<n; i++){ // 1,2,3,..., n-1 coins are there
            for(int j=1; j<=n; j++){ // Sum is n
                dp[i][j] = dp[i-1][j]%mod;
                if( j >= i ){
                    dp[i][j] = (dp[i][j] + dp[i][j-i])%mod;
                }
            }
        }
        return dp[n-1][n];
    }
};

// Space optimized solution to coin change problem
class Solution {
  public:
    // Function to find out the number of ways to use the coins to
    // sum up to a certain required value.
    long long numberOfWays(int coins[], int n, int value) {
        long long dp[2][value+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=value; j++){
                if(j==0){
                    dp[i%2][j] = 1;
                }
                else if(i==0){
                    dp[i][j] = 0;
                }
                else if(j >= coins[i-1]){
                    dp[i%2][j] = (dp[i%2][j-coins[i-1]] + dp[(i-1)%2][j]);
                }
                else{
                    dp[i%2][j] = dp[(i-1)%2][j];
                }
            }
        }
        
        return dp[n%2][value];
    }
};