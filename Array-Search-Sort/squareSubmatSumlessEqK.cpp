#include <bits/stdc++.h>
using namespace std;

/*
Given a 2-dimensional matrix of size ‘N’ x ‘M’ and an integer K. Find the size of the largest square 
sub-matrix whose sum is less than or equal to K. The size of a matrix is the product of rows and columns in it.

A sub-matrix is a matrix obtained from the given matrix by deletion of several (possibly, zero or all) 
rows/columns from the beginning and several (possibly, zero or all) rows/columns from the end. 
A square matrix is a matrix which has the same number of rows and columns.
*/

bool isPossible(vector<vector<int>> &mat, int n, int m, int k, int s) {
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

    // Build prefix sum matrix
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    // Check all s x s squares
    for(int i = s; i <= n; i++){
        for(int j = s; j <= m; j++){
            int sum = prefix[i][j] - prefix[i-s][j] - prefix[i][j-s] + prefix[i-s][j-s];
            if(sum <= k) return true;
        }
    }
    return false;
}

int largestSquareSubmatrix(vector<vector<int>> &mat, int n, int m, int k)
{
	int ans=0;
    int high = min(m,n);
    int low = 1;
    int mid;

    while(low <= high){
        mid = low + (high-low)/2;
        if(isPossible(mat, n, m, k, mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return (ans*ans);
}
