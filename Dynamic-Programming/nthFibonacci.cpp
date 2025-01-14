#include<bits/stdc++.h>
using namespace std;

//// Top down recursion and memoization approach is used here.

//// Calculating the nth fibonacci number using dynamic programming.

long long fib(int n, vector<long long> &dp){
    /// base case 
    if(n<=1) return n;

    /// if already have answer 
    if(dp[n] != -1) return dp[n];   //// this prevents from further call as we have already calculated the some fibonacci numbers.

    //// if calculate nth value and then return;
    dp[n] = fib(n-1, dp) + fib(n-2, dp);

    return dp[n];
}

//// Tabulation approach to calculate nth fibonacci number;
/// this method is bottom - up approach to calculate nth fibonacci number.
long long tabfib(int n){
    vector<long long> dp(n+1);

    if(n<=1) return n;

    dp[0] = 0; dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];

}

int main(){
    int n;
    cin >> n;
    vector<long long> v(n+1, -1);
    cout << n << "th fibonacci number using top-down : " << fib(n, v) << endl;
    cout << n << "th fibonacci number using bottom-up : " << tabfib(n) << endl;
}