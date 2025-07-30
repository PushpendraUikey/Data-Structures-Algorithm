#include <bits/stdc++.h>
using namespace std;

/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous
*/

int lcs_brute(char* X, char*Y, int n, int m){
    if(n==0 || m==0) return 0;

    if(X[n-1] == Y[m-1]){
        return 1 + lcs_brute(X, Y, n-1, m-1);
    }
    else{
        return max(lcs_brute(X, Y, n-1, m), lcs_brute(X, Y, n, m-1));
    }
}

// With Top-Down memoization
int lcs_eff(char*X, char*Y, int n, int m, vector<vector<int>>&dp){
    if(n==0 || m==0) return 0;

    if(X[n-1] == Y[m-1]){
        return dp[n][m] = 1 + lcs_eff(X, Y, n-1, m-1, dp);
    }

    if(dp[n][m] != -1) return dp[n][m];

    return dp[n][m] = max(lcs_eff(X, Y, n-1, m, dp), lcs_eff(X, Y, n, m-1, dp));
}

// Bottom Up memoization: Tabularization
int lcs_opt(char*X, char*Y, int n, int m){
    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

// %%%%%%%%%%%%%%%%%%%% Application of LCS %%%%%%%%%%%%%%%%%%%%%%

// 1. diff utility:- You find out the LCS of the two files(two versions), Whatever is extra in the first
// is removed from the second file(version) and whatever is extra in second file(version) is added into
// second file(version)

// 2. Minimum insertions and deletions to convert S1 into S2
// let l be length of Common Subsequence then s1.length - l be the deletions and s2.length - l be the 
// insertions to convert s1 into s2

// 3. Shortest Common SuperSequence
// SuperSequence is the sequence that contains both s1 and s2 as a subsequence
// It's length being: l + (s1.length - l) + (s2.length - l)

// 4. Longest Palindromic SubSequence
// In a string S find the longest palindromic subsequence, find the longest common subsequence in S & reverse(S)

// 5. Longest Repeating Subsequence
// Given a string S, make a copy Sc then run the LCS algorithm, with one more condition when the last two 
// characters match, index should not be same in S and Sc then only go in the condition where you increase 
// the length of subsequence ending at the index (i, j) in dp array

// 6. Space optimized DP solution of LCS
int lcs_spOpt(char *X, char *Y, int n, int m){
    int dp[2][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                dp[i % 2][j] = 0;
            else if(X[i - 1] == Y[j - 1])
                dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
            else
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
        }
    }

    return dp[n % 2][m];
}

// 7. Printing the LCS 
// Traverse the 2D array from last position of 2D array and if the last characters match print and go
// diagonally up else go to that direction which has maximum value in it.
void printLCS(int**dp, char*X, char*Y, int n, int m){
    int len = dp[n][m];
    char str[len + 1];
    str[len] = '\0';    // Null Terminator
    int idx = len-1;
    while(n>0 && m>0){
        if(X[n-1] == Y[m-1]){
            str[idx--] = X[n-1];
            n--; m--;
        }
        else if(dp[n-1][m] > dp[n][m-1]){
            n--;
        }
        else{
            m--;
        }
    }
    cout << str << endl;
}