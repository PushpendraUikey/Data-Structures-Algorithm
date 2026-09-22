#include <bits/stdc++.h>
using namespace std;

/***
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

class Solution {

public:
    int climbStairs(int n) {
        vector<int> ans(n+1);
        ans[0] = 1;
        ans[1] = 1;
        for(int i=2; i<=n; i++) {
            ans[i] = ans[i-1] + ans[i-2];
        }

        return ans[n];
    }
};