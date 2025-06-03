#include<bits/stdc++.h>
using namespace std;

/* Here is the algorithm to rotate a matrix by 90 degree*/
/* It's a bit tricky and depends on if you can observe */
void rotate(vector<vector<int> >& mat) {
    
    int n = mat.size();
    
    //// first transpose the matrix
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    //// then reverse each row
    for(int i=0; i<n; i++){
        int b=0;
        int e=n-1;
        while(b<e){
            swap(mat[i][b], mat[i][e]);
            b++;
            e--;
        }
    }
    
}