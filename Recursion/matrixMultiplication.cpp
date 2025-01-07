#include<bits/stdc++.h>
using namespace std;

/*matrix mutltiplication*/

vector<vector<int>> matrixGame(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n,0));
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res[k][i] += (mat[k][j] * mat[j][i]);   // min 3 loops are required to do matrix multiplication.
            }
        }
    }
    return res;
}