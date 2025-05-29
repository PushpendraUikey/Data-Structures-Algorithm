#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int stRow = 0; int stCol = 0;
        int row = matrix.size(); int col = matrix[0].size();
        int endRow = row-1; int endCol = col-1;
        
        int total = row * col;
        int count = 0;
        vector<int> ans;
   
        while( count < total){

            for(int i{stCol}; count < total && i <= endCol; i++){
                ans.push_back( matrix[stRow][i] );
                count++;
            }
            stRow++;
            
            for(int i{stRow}; count < total && i<= endRow; i++){
                ans.push_back( matrix[i][endCol] );
                count++;
            }
            endCol--;
            
            for(int i{endCol}; count < total && i>=stCol; i--){
                ans.push_back( matrix[endRow][i] );
                count++;
            }
            endRow--;
            
            for(int i{endRow}; count < total && i>=stRow; i--){
                ans.push_back( matrix[i][stCol]);
                count++;
            }
            stCol++;
        }
        return ans;
    }
};

int main(){
    int n, m; cin >> n >> m;
    int k;
    vector<vector<int>> matrix;

    for(int i{0}; i<n; i++){
        vector<int> temp;
        for(int j{0}; j<m; j++){
            cin>>k;
            temp.push_back(k);
        }
        matrix.push_back(temp);
    }
    Solution sb;
    vector<int> ans = sb.spiralOrder(matrix);
    
}