#include <bits/stdc++.h>
using namespace std;

//  minq(a,b) = min(minq(a,a+b-1),minq(a+w,b)),

// Here's the recursive solution to the problem
int __min(std::vector<int>&arr, int a, int b){
    // base case 
    if(a==b){
        return arr[a];
    }
    int w = std::pow(2, (int)std::log2(b-a+1));
    int _mini1 = __min(arr, a, a+w-1);
    int _mini2 = __min(arr, a+w, b);

    return std::min(_mini1, _mini2);
}
// The above implementation is quite efficient when there are a large number of queries and n is also
// larger. In that case we can use DP to store already calculated range mini's reducing computation effort