#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        function<int(int, int, int)> dfs = [&](int i, int j, int xorVal) {
            if (i >= m || j >= n) return INT_MAX;
            xorVal ^= grid[i][j];
            if (i == m - 1 && j == n - 1) return xorVal;
            if (dp[i][j][xorVal] != -1) return dp[i][j][xorVal];
            int right = dfs(i, j + 1, xorVal);
            int down = dfs(i + 1, j, xorVal);
            return dp[i][j][xorVal] = min(right, down);
        };
        return dfs(0, 0, 0);
    } 
};
