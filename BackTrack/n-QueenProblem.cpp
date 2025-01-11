#include<bits/stdc++.h>
using namespace std;

/// @brief We have to place n-queens in a n*n chess board so that no queen is being attacked

class Solution{
    bool isSafe(int row, int col, vector<vector<int>>& queenPlace, int n){
        //// since we are filling the queens from left direction, thus we 
        // need to check the left direction only
        
        /// check for the left side row.
        int i = row;
        int j = col;
        
        while(j>=0){
            if(queenPlace[i][j] == 1){
                return false;
            }
            j--;
        }
        
        /// check for the diagonal up.
        i = row;
        j = col;
        
        while(j>=0 && i>=0){
            if(queenPlace[i][j] == 1){
                return false;
            }
            i--;
            j--;
        }
        
        /// check for the diagonal down.
        i = row;
        j = col;
        
        while(j>=0 && i < n){
            if(queenPlace[i][j] == 1){
                return false;
            }
            i++;
            j--;
        }
        
        /// if all passed
        return true;
    }
    
    void addAnswer(vector<vector<int>>& ans, vector<vector<int>>& queenPlace, int n){
        vector<int> temp;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(queenPlace[j][i] == 1){
                    temp.push_back(j+1);    /// we need the rows of each col where we have kept them
                }
            }
        }
        
        ans.push_back(temp);
    }
    void solve(int col,vector<vector<int>>& ans, vector<vector<int>>& queenPlace, int n){
        if(col == n){
            addAnswer(ans, queenPlace, n);
            return;
        }
        
        //// place one queen at safe place and let the recursion do rest 
        /// go through each row and check where to place
        for(int i=0; i<n; i++){
            if(isSafe(i, col, queenPlace, n)){
                queenPlace[i][col] = 1;
                /// call to place the queen in next row
                solve(col+1,ans, queenPlace, n);
                
                //// Here comes the backTracking
                queenPlace[i][col] = 0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> queenPlace(n, vector<int>(n,0)); /// to check if quen can be placed.
        
        int col = 0;
        solve(col, ans, queenPlace, n);
        
        return ans;
    }
};