#include <bits/stdc++.h>
using namespace std;

// We want to evaluate a degree n-1 polynomial P(x) = a0 + a1x + a2x2 +...+an-1xn-1 at a given
//  point x = alpha.
//  Input: integers a0, a1 ...
//  an-1 in an array. And an integer .
//  Output: a0 +a1alpha +a2alpha2+ +an-1alphan-1
//  Design an algorithm for this which uses only O(n) multiplications and additions.

long long computePoly(std::vector<int>&coeff, int alpha){
    int n = coeff.size();

    long long ans = 0;
    long long XX_alpha = 1;
    for(int i=0; i<n; i++){
        ans += (coeff[i]*XX_alpha);
        XX_alpha *= alpha;
    }

    return ans;
}