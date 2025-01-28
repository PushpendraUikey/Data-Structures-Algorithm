#include <bits/stdc++.h> 
using namespace std;

// You are given a 2-D matrix of dimensions 'N' x 'M', each row of the matrix is sorted in 
// non-decreasing order, and each column is sorted in non-decreasing order.
// You are also given an integer ‘X’. You are supposed to find whether 'X' is present in 
// the given matrix.

bool findInMatrix(int x, vector<vector<int>> &arr)
{
    //    Write your code here.
    int row = arr.size();
    int col = arr[0].size();

    int i1=row-1, j1=0;
    int i2=0, j2=col-1;

    while(j1<=j2 && i1>=i2){
        if(x == arr[i1][j1]) return true;
        else if(x > arr[i1][j1]){
            j1++;
        }else{
            i1--;
        }

        if(x == arr[i2][j2]) return true;
        else if(x > arr[i2][j2]){
            i2++;
        }else{
            j2--;
        }
    }

    return false;
}