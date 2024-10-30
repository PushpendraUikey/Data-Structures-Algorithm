#include <bits/stdc++.h>
using namespace std;

//// Here is the code to find nth fibonacci using matrix exponentiation, quite efficient to find large fibonacci numbers


const int mod = 1e9+7;
void multiply(vector<vector<long long>>& a, vector<vector<long long>>& b){
    long long a1 = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%mod;
    long long a2 = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%mod;
    long long a3 = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%mod;
    long long a4 = (a[1][0]*b[0][1] + a[1][1]*b[1][1])%mod;

    a[0][0] = a1;
    a[0][1] = a2;
    a[1][0] = a3;
    a[1][1] = a4;
}
void matrixpower(vector<vector<long long>>& matrix, int n){
    if(n==0 || n==1){
        return;
    }
    vector<vector<long long>> base = {{1, 1} , {1 , 0 }};

    matrixpower(matrix, n/2);
    
    multiply(matrix, matrix);

    if(n%2!=0){
        multiply(matrix, base);
    }
}
int fibonacciNumber(int n){
    if(n==0) return 0;

    vector<vector<long long>> matrix = { {1, 1} ,{1, 0}};

    matrixpower( matrix, n-1);

    int ans = matrix[0][0];
    
    return ans;
}

int main(){
    int n; 
    cout << "Give N: ";
    cin >> n;

    cout << "Fiboncci is : " << fibonacciNumber(n) << endl;
}