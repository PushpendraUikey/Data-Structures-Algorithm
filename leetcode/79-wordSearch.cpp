#include <bits/stdc++.h>
using namespace std;

/*
    This BFS solution is not correct since shared visited matrix blocks valid paths because different
    routes might need to cross the same cell at different times.
    A DFS solution is more appropriate for this, since it can backtrack and explore all possible paths without
    being blocked by a shared visited matrix.
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;

        char c = word[0];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++){
                if(board[i][j] == c){
                    q.push({i,j});
                }
            }
        }

        int rx[4] = {1, -1, 0, 0};
        int cy[4] = {0, 0, -1, 1};
        while(!q.empty()){
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int idx = 0;
            auto [x, y] = q.front(); q.pop();

            queue<tuple<int,int, int>> tq;
            tq.push({x, y, idx});
            visited[x][y] = true;

            while(!tq.empty()){
                auto [tx, ty, tidx] = tq.front(); tq.pop();
                cout << "tx: " << tx << "  ty: " << ty << endl;
                if (tidx+1 == word.length()){
                    return true;
                }
                for(int i=0; i<4; i++){
                    int nx = tx + rx[i];
                    int ny = ty + cy[i];

                    if(nx >=0 && nx < m && ny >=0 && ny < n && !visited[nx][ny]) {
                        if(board[nx][ny] == word[tidx+1]){
                            tq.push({nx, ny, tidx+1});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
        return false;
    }
};