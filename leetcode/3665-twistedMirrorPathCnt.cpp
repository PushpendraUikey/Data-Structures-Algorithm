#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1000000007;
    int solve(vector<vector<int>>& grid, vector<vector<int>>&memo, int y, int x) {
        int m = grid.size();
        int n = grid[0].size();

        if (y == m-1 && x == n-1) return 1;
        if (memo[y][x] != -1) return memo[y][x];

        int cnt = 0;

        if (y < m-1) {
            int ny = y + 1;
            int nx = x;
            bool down = false; 
            while(ny < m && nx < n && grid[ny][nx] == 1) {
                if(down){
                    ny = ny+1;
                }
                else{
                    nx = nx+1;
                }
                down = !down;
            }
            if( ny < m && nx < n) {
                cnt += solve(grid, memo, ny, nx)%mod;
            }
        }
        if (x < n-1) {
            int nx = x + 1;
            int ny = y;
            bool down = true;
            while( ny < m && nx < n && grid[ny][nx] == 1) {
                if (down) {
                    ny = ny + 1;
                }else {
                    nx = nx + 1;
                }
                down = !down;
            }
            if (ny < m && nx < n) {
                cnt += solve(grid, memo, ny, nx)%mod;
            }
        }

        return memo[y][x] = cnt%mod;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        if( grid[m-1][n-1] == 1) return 0;
        return solve(grid, memo, 0, 0);
    }
};