#include <bits/stdc++.h>
using namespace std;

// The problem is related to partitioning a natural number—counting 
// the number of ways a natural number n can be expressed as a sum of positive integers. 
// This is commonly referred to as the partition function in mathematics.


// Recursive: O(n^2)
int call=0;
long long solve(vector<long long>&f, int n){
    call++;
    if(n==0) return 1;
    if(f[n] != -1){
        return f[n];
    }
    long long sum = 0;
    for(int i=n-1; i >= 0 ; i--){
        if(f[i] != -1){
            sum += f[i];
        }else{
            sum += solve(f, i);
        }
    }
    return f[n] = sum;
}
long long __countWays(int n){
    vector<long long> f(n+1, -1);
    return solve(f, n);
}

// A simple answer to the problem is 2^(n-1)

int main(){
    int n; cout <<"Give the number: " ; cin  >> n;
    std::cout << __countWays(n) << " : Recursive function. " << endl;
    std::cout << "No of calls made: " << call << endl;
}