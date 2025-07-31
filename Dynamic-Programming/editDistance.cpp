#include <bits/stdc++.h>
using namespace std;

/*
Given two strings str1 and str2 and below operations that can be performed on str1. 
Find minimum number of edits (operations) required to convert 'str1' into 'str2'.  
Insert
Remove
Replace
All of the above operations are of equal cost. 
*/

int countEditDistance(const string& s1, const string&s2, int n, int m){
    if(n==0) return m; // need to insert m char of s2
    if(m==0) return n; // need to delete n char of s1

    if(s1[n-1] == s2[m-1]){
        return countEditDistance(s1, s2, n-1, m-1);
    }
    else{ // Assuming each operation costs one unit cost!
        return 1 + min(
            countEditDistance(s1, s2, n-1, m-1),    /*replaced last char of s1 to last char of s2*/
            min(
                countEditDistance(s1, s2, n, m-1), /*inserted last char of s2 to s1 (n+1 will match to m)*/
                countEditDistance(s1, s2, n-1, m) /*deleted last char of s1*/
            )
        );
    }
}

// Efficient method using Tabulation!!!
int countEditDistance_eff(const string&s1, const string&s2, int n, int m){
    int dp[n+1][m+1];
    // for(int i=0; i<=n; i++){
    //     dp[i][0] = i;
    // }
    // for(int j=0; j<=m; j++){
    //     dp[0][j] = j;
    // }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==0){
                dp[i][j] = j;
            }
            else if(j==0){
                dp[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(
                    dp[i-1][j-1],   // replace
                    min(
                        dp[i-1][j], // delete
                        dp[i][j-1]  // insert
                    )
                );
            }
        }
    }
    return dp[n][m];
}

// Can be further optimized to get the O(m) space : 2 X m array!
