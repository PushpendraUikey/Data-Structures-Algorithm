#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n, vector<int>&costs, vector<int>&mincost) {
        if(n<=0) return 0;
        if(mincost[n] != -1) return mincost[n];

        int curr = costs[n-1];
        int curr1 = solve(n-1, costs, mincost) + 1;
        int curr2 = solve(n-2, costs, mincost) + 4;
        int curr3 = solve(n-3, costs, mincost) + 9;

        curr = curr + min(curr1, min(curr2, curr3));
        return mincost[n] = curr;
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> mincost(n+1, -1);
        return solve(n, costs, mincost);
    }
};

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n == 1) return costs[0] + 1;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = costs[0] + 1;
        dp[2] = min(dp[1] + 1, 4) + costs[1];

        for(int i=3; i<=n; i++) {
            int c1 = dp[i-3] + 9;
            int c2 = dp[i-2] + 4;
            int c3 = dp[i-1] + 1;
            dp[i] = min(c1, min(c2, c3)) + costs[i-1];
        }

        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n == 1) return costs[0] + 1;
        int c1 = 0;
        int c2 = costs[0] + 1;
        int c3 = min(4, c2+1) + costs[1];
        int c4;

        for(int i=3; i<=n; i++) {
            c4 = costs[i-1] + min(c1+9, min(c2+4, c3+1));
            c1 = c2;
            c2 = c3;
            c3 = c4;
        }
        return c3;
    }
};