#include <bits/stdc++.h>
using namespace std;

// problem is to find a path from the upper-left corner to the lower-right
// corner of an n*n grid, such that we only move down and right. Each square
// contains a positive integer, and the path should be constructed so that the sum of
// the values along the path is as large as possible.

// sum(y,x) = max(sum(y,x 1),sum(y 1,x))+value[y][x], this recursion will be used

int MaxPathsum(std::vector<std::vector<int>>&values){
    int n = values.size();
    std::vector<std::vector<int>> sum(n, vector<int>(n,0));

    for(int i=1; i<n; ++i){
        for(int j=1; j<n; ++j){
            sum[i][j] = max(sum[i][j-1], sum[i-1][j]) + values[i][j];
        }
    }
    return sum[n-1][n-1];
}