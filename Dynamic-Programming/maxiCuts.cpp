#include <bits/stdc++.h>
using namespace std;

// Given inputs n, a, b, c: We have to make cuts of n in such a way that each piece of length a, b or c
// What is the maximum number of cuts we can make.

// Recursive inefficient solution
int maximumCut(int n, const int& a, const int& b, const int& c){
    if(n<0) return -1;
    if(n==0) return 0;

    int res = max(
        maximumCut(n-a,a,b,c),
        max(
            maximumCut(n-b,a,b,c),
            maximumCut(n-c,a,b,c)
        )
    );
    if(res==-1) return res;
    else return res+1;
}

// Solution to the maximumCut using Tabulation
int maximumCut_eff(int n, const int&a, const int&b, const int&c){
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = -1;
        if(i-a >= 0) dp[i] = max(dp[i], dp[i-a]);
        if(i-b >= 0) dp[i] = max(dp[i], dp[i-b]);
        if(i-c >= 0) dp[i] = max(dp[i], dp[i-c]);
        if(dp[i] != -1) dp[i]++;
    }
    return dp[n];
}