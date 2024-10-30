#include<bits/stdc++.h>
using namespace std;

// In any row elements are in non-decreasing order, and first element
// of any row is greater than last element of previous row.
//// Elements are in non-decreasing order throughout the row major.
/*
1 2 3 4 5 6 
7 8 9 10 11 12 so on
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int s = 0;
        int e = row * col - 1;

        int m = s + (e-s)/2;

        while( e >= s){
            int element = matrix[m/col][m%col];         // this actually solves the problem(trick)

            if (element == target) return true;
            else if(element > target) {
                e = m - 1;
            }else{
                s = m + 1;
            }
            m = s + (e-s)/2;
        }
        return 0;
    }
};