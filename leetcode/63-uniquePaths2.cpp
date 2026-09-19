#include <bits/stdc++.h>
using namespace std;

class Solution {
    int path(int x, int y, vector<vector<int>>&Obstacle, vector<vector<int>>&ans) {
        int m = Obstacle.size();
        int n = Obstacle[0].size();
        if(Obstacle[x][y] == 1) return 0;
        if( x == m-1 && y == n-1) return 1;
        if(ans[x][y] != -1) return ans[x][y];

        int t = 0;
        if ( x < m-1 ) {
            t += path(x+1, y, Obstacle, ans);
        }
        if ( y < n-1 ) {
            t += path(x, y+1, Obstacle, ans);
        }

        return ans[x][y] = t;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        return path(0, 0, obstacleGrid, ans);
    }
};