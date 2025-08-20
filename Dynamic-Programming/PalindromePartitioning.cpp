#include <bits/stdc++.h>
using namespace std;

// This problem is inspired from matrix chain multiplication optimization.
// Minimum number of cuts required to make each part of string after cut a palindrome.

bool isPalindrome(const string&str, int s, int e){
    while(s<e){
        if(str[s] != str[e]) return false;
        s++; e--;
    }
    return true;
}
int palPart(const string&str, int i, int j){
    if(isPalindrome(str, i, j)) return 0;

    int res = INT_MAX;

    for(int k=i; k<j; k++){
        res = min(res, 1+palPart(str, i, k)+palPart(str, k+1, j));
    }

    return res;
}
// The above solution can obviouslly be optimized using memoization

// Tabulation based solution for palindrome partitioning.
int palPart_tab(const string&str){
    int len = str.length();

    int dp[len][len];   // dp[i][j] will have the minimum cuts required for substring S[i...j]

    for(int i=0; i<len; i++) dp[i][i] = 0;

    for(int gap=1; gap<len; gap++){
        for(int i=0; i+gap<len; i++){
            int j = i+gap;

            if(isPalindrome(str, i, j)) dp[i][j] = 0;   // This part can be optimized:No need to call isPalindrome
            else{
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; k++){
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][len-1];
}