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
