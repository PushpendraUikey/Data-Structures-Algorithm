#include<bits/stdc++.h>
using namespace std;

/// @brief following in the sudoku solver algorithm with time complexity O(9^m) where m is number of emtpy cell
/// the follwing sudoku is 9*9, and recursive algorithm takes O(1) space here


bool isSafe(int& i, int& j,vector<vector<int>>& sudoku, int &val){
    int n = sudoku.size();

    for(int k=0; k<n; k++){
        /// row check
        if(sudoku[i][k] == val) return false;

        /// column check
        if(sudoku[k][j] == val) return false;

        //// 3*3 matrix check(This is the formula to be remembered.)
        if(sudoku[3*(i/3) + k/3][3*(j/3) + k%3]==val){
            return false;
        }
    }
    //// safe hai
    return true;
}


bool solve(vector<vector<int>>& sudoku){
    int n = sudoku.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(sudoku[i][j] == 0){
                for(int val = 1; val<= n; val++){
                    if(isSafe(i, j, sudoku, val)){
                        sudoku[i][j] = val;
                        // recursive call
                        bool solPossible = solve(sudoku);
                        if(solPossible){
                            return true;
                        }else{
                            //// backTrack
                            sudoku[i][j] = 0;
                        }
                    }
                }
                //// solution at the end nhi mila
                return false;
            }
        }
    }
    //// yha pahuch gaye to solution mil hi gya hai
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}