#include <bits/stdc++.h>
using namespace std;


class Solution {
    int solvecol(vector<vector<int>>&grid, vector<bool>&viscol, vector<bool>&visrow, int x, int y){
        if(viscol[x]) return 0;
        int m = grid.size();
        viscol[x] = true;

        int count = 0;
        for(int i=0; i<m; i++) {
            if(grid[i][x] == 1){
                grid[i][x] = 2;
                count++;
                count += solverow(grid, viscol, visrow, x, i);
            }
        }
        return count;
    }
    int solverow(vector<vector<int>>&grid, vector<bool>&viscol, vector<bool>&visrow, int x, int y){
        if(visrow[y]) return 0; // prevent double count
        int n = grid[0].size();
        visrow[y] = true;

        int count = 0;
        for(int i=0; i<n; i++){
            if(grid[y][i] == 1) {
                grid[y][i] = 2;
                count++;
                count += solvecol(grid, viscol, visrow, i, y);
            }
        }
        return count;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> visrow(m, false);
        vector<bool> viscol(n, false);

        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1){
                    grid[i][j] = 2;
                    int col = solvecol(grid, viscol, visrow, j, i);
                    int row = solverow(grid, viscol, visrow, j, i);
                    if(col + row > 0){
                        count += (col + row + 1);
                    }
                }
            }
        }

        return count;
    }
};

// Copilot Solution
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};