#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calculate(string& s, string& t, int m, int n, vector<vector<int>>& dp) {
        if(n == 0) return 1;
        if(m == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];

        if(s[m-1] == t[n-1]) {
            return dp[m][n] = calculate(s, t, m-1, n-1, dp) + calculate(s, t, m-1, n, dp);
        } else {
            return dp[m][n] = calculate(s, t, m-1, n, dp);
        }
    }

    public:
        int numDistinct(string s, string t) {
            int m = s.length();
            int n = t.length();
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
            return calculate(s, t, m, n, dp);
        }
};