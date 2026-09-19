#include <bits/stdc++.h>
using namespace std;


class Solution {
    int path(int x, int y, int m, int n, vector<vector<int>>&ans) {
        if(x == m-1 && y == n-1) return 1;
        if(ans[x][y] != -1) return ans[x][y];
        int t = 0;
        if( x < m - 1) {
            t += path(x+1, y, m, n, ans);
        }
        if( y < n - 1) {
            t += path(x, y+1, m, n, ans);
        }

        return ans[x][y] = t;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        return path(0, 0, m, n, ans);
    }
};