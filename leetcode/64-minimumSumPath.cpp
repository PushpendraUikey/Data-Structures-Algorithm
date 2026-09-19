#include <bits/stdc++.h>
using namespace std;

/* 
    More efficient solution using memoization.
    In this approach I'm trying to keep the optimal path sum from the current cell to the end cell.
*/

class Solution {
    int solve(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&ans){
        int m = grid.size(); int n = grid[0].size();
        if( x == m-1 && y == n-1 ) {
            return grid[x][y];
        }
        
        if(ans[x][y] != -1) return ans[x][y] + grid[x][y];

        int t = INT_MAX;
        if( x < m-1 ){
            t = min(t, solve(x+1, y, grid, ans));
        }
        if( y < n-1 ){
            t = min(t, solve(x, y+1, grid, ans));
        }
        if(t == INT_MAX) return t;
        ans[x][y] = t;
        return grid[x][y] + t;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        return solve(0, 0, grid, ans);
    }
};

/* Inefficient TLE for the following solution 
    In this approach I'm trying to keep the optimal path sum from the beginning to the current cell
*/
class Solution {
    void solve(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&ans, int&currsum, int&minsum){
        int m = grid.size(); int n = grid[0].size();
        if( x == m-1 && y == n-1 ) {
            currsum += grid[x][y];
            if(minsum > currsum) minsum = currsum;
            currsum -= grid[x][y];
            return;
        }
        if(ans[x][y] != -1 && ans[x][y] < currsum) return;
        ans[x][y] = currsum;

        currsum += grid[x][y];
        
        if( x<m-1 ){
            solve(x+1, y, grid, ans, currsum, minsum);
        }
        if( y<n-1 ){
            solve(x, y+1, grid, ans, currsum, minsum);
        }
        currsum -= grid[x][y];

        return;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int currsum = 0;
        int minsum = INT_MAX;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        solve(0, 0, grid, ans, currsum, minsum);
        return minsum;
    }
};