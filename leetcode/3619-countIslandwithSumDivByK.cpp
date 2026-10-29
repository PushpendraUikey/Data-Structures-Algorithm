#include <bits/stdc++.h>
using namespace std;

class Solution {
    int K;
    int solve(vector<vector<int>>&grid, int x, int y) {
        int m = grid.size();
        int n =  grid[0].size();
        int val = grid[x][y]%K;
        grid[x][y] = 0;

        if(x>0 && grid[x-1][y] != 0) val += solve(grid, x-1, y)%K;
        if(x<m-1 && grid[x+1][y] != 0) val += solve(grid, x+1, y)%K;
        if(y>0 && grid[x][y-1] != 0) val += solve(grid, x, y-1)%K;
        if(y<n-1 && grid[x][y+1] != 0) val += solve(grid, x, y+1)%K;

        return val%K;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        K = k;
        int island = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if(grid[i][j] != 0){
                    int sum = solve(grid, i, j);
                    if(sum%k == 0) island++;
                }
            }
        }

        return island;
    }
};