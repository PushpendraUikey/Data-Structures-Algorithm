#include <iostream>
using namespace std;

// Following algorithm can be used to calculate the nth fibonacci number in log(n) time using 
// Matrix exponentiation.
// Following recursion is useful:   [F(n), F(n-1)] = [[1,1][1,0]][F(n-1), F(n-2)]


// Multiply two 2x2 matrices
void multiply_matrices(long long a[2][2], long long b[2][2]){
    long long x = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    long long y = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    long long z = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    long long w = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = w;

}

// computing matrix multiplication using repeated squaring.
void matrix_exponentiation(long long mat[2][2], int n){
    if(n==0 || n==1) return;

    matrix_exponentiation(mat, n/2);
    multiply_matrices(mat, mat);
    long long b[2][2] = {{1,1,}, {1,0}};
    if(n&1){
        multiply_matrices(mat, b);
    }
}

// Compute Fibonacci using matrix exponentiation
long long fibonacci(long long n) {
    if (n == 0)
        return 0;
    long long mat[2][2] = {{1, 1}, {1, 0}};
    matrix_exponentiation(mat, n - 1);
    return mat[0][0]; // Top-left element of the matrix
}

int main() {
    long long n = 10; // Example: Find the 10th Fibonacci number
    cout << "F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
