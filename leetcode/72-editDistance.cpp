#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>&ans, string&word1, string&word2, int n, int m) {
        if(n==0 && m==0) return 0;
        if(n==0) return m;
        if(m==0) return n;
        if(ans[n][m] != -1) return ans[n][m];

        int sol0 = solve(ans, word1, word2, n-1, m-1);
        if( word1[n-1] == word2[m-1] ) {
            return ans[n][m] = sol0;
        }
        int sol1 = solve(ans, word1, word2, n-1, m);
        int sol2 = solve(ans, word1, word2, n, m-1);

        return ans[n][m] = min(min(sol1, sol2), sol0) + 1;
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> ans(n+1, vector<int>(m+1, -1));
        return solve(ans, word1, word2, n, m);
    }
};