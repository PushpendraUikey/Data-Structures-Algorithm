#include <bits/stdc++.h> 
using namespace std;

/*
Solution to find the ways to reach the Nth stair from the oth stare
Problem's solution is same as of Fibonacci, use recursion, ways to reach nth 
stair is ways to reach (n-1)th + (n-2)th
*/
const int mod = 1e9+7;
void multiply(vector<vector<int>>& a, vector<vector<int>>& b){
    int a1 = (1LL*a[0][0]*b[0][0] + 1LL*a[0][1]*b[1][0])%mod;
    int a2 = (1LL*a[0][0]*b[0][1] + 1LL*a[0][1]*b[1][1])%mod;
    int a3 = (1LL*a[1][0]*b[0][0] + 1LL*a[1][1]*b[1][0])%mod;
    int a4 = (1LL*a[1][0]*b[0][1] + 1LL*a[1][1]*b[1][1])%mod;

    a[0][0] = a1;
    a[0][1] = a2;
    a[1][0] = a3;
    a[1][1] = a4;
}
void matrixpower(vector<vector<int>>& matrix, int n){
    if(n==0 || n==1){
        return;
    }
    vector<vector<int>> base = {{1, 1} , {1 , 0 }};

    matrixpower(matrix, n/2);
    
    multiply(matrix, matrix);

    if(n%2!=0){
        multiply(matrix, base);
    }
}
int fibonacciNumber(int n){
    if(n==0) return 0;

    vector<vector<int>> matrix = { {1, 1} ,{1, 0}};

    matrixpower( matrix, n-1);

    int ans = (matrix[0][0] * 1LL + matrix[0][1] *1LL)%mod;   //// because base cases are diff i.e. F(n<=1) = 1; Hence fibonacci is pdt with matrix (1,1);
    
    return ans;
}
int countDistinctWays(int nStairs) {
    if(nStairs <= 1) return 1;
    return fibonacciNumber(nStairs);
}