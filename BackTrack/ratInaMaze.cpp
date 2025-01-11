#include<bits/stdc++.h>
using namespace std;


bool isSafe(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& maze, int n){
    if( (x>=0 && x<n) && (y>=0 && y<n) && vis[x][y] == 0 && maze[x][y]==1){ // index under bound, not visited, and is not a wall(i.e. 0)
                                        //// and not visited as well
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>>&maze, int n, string path, vector<vector<int>> &vis, vector<string>&ans){
    /// base case to recursion 
    if( x==n-1 && y == n-1){        /// Reached the destination
        ans.push_back(path);
        return;
    }

    /// 4 steps D, L, R, U      // this order because we want lexicographic answers.
    // for down;
    if(isSafe(x+1,y, vis, maze, n)){
        vis[x][y] = 1;
        
        solve(x+1, y, maze, n, path+"D", vis, ans);

        vis[x][y] = 0;      //// this part here is backTracking

    }

    /// for left
    if(isSafe(x,y-1, vis, maze, n)){
        vis[x][y] = 1;
        
        solve(x, y-1, maze, n, path+"D", vis, ans);

        vis[x][y] = 0;      //// this part here is backTracking

    }

    //// for right
    if(isSafe(x, y+1 , vis, maze, n)){
        vis[x][y] = 1;
        
        solve(x, y+1, maze, n, path+"D", vis, ans);

        vis[x][y] = 0;      //// this part here is backTracking

    }

    //// for up
    if(isSafe(x-1,y, vis, maze, n)){
        vis[x][y] = 1;
        
        solve(x-1, y, maze, n, path+"D", vis, ans);

        vis[x][y] = 0;      //// this part here is backTracking

    }
}


vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0) return ans;
        int x = 0;
        int y = 0;
        vector<vector<int>> visited(n, vector<int>(n,0));
        string path ="";
        
        solve(x, y, m, n, path, visited, ans);
        return ans;
    }