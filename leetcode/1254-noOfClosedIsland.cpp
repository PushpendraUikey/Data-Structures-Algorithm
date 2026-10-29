#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<vector<int>>&grid, int x, int y, bool&c){
        int m = grid.size(); int n = grid[0].size();
        if(grid[x][y] != 0) return;
        grid[x][y] = 2; // mark as visited first.

        if(x-1 < 0 || x+1 == m || y-1 < 0 || y+1 == n) {
            c = false;
        }
        if(x-1 >= 0 && grid[x-1][y] == 0) {
            solve(grid, x-1, y, c);
        }
        if(x+1 < m  && grid[x+1][y] == 0) {
            solve(grid, x+1, y, c);
        }
        if(y-1 >= 0 && grid[x][y-1] == 0) {
            solve(grid, x, y-1, c);
        }

        if(y+1 < n  && grid[x][y+1] == 0) {
            solve(grid, x, y+1, c);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        int island = 0;

        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    bool isclosed = true;
                    solve(grid, i, j, isclosed);
                    if(isclosed) island++;
                }
            }
        }

        return island;
    }
};