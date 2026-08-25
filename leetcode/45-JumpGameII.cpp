#include <bits/stdc++.h>
using namespace std;


// Memoization
class Solution {
    int solve(vector<int>&nums, vector<int>&ans, int idx) {
        if(idx == 0) return ans[0] = 0;
        if(idx < 0) return 1e9;

        int minstep = INT_MAX;
        for(int i=idx-1; i>=0; i--) {
            if(nums[i]+i >= idx){

            if(ans[i] < 0) ans[i] = solve(nums, ans, i);
            minstep = min(minstep, ans[i]+1);

            }
        }

        return ans[idx] = minstep;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        return solve(nums, ans, n-1);

    }
};


// Tabulation
class Solution {
    
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, INT_MAX);

        ans[0] = 0;

        for(int i=0; i<n; i++) {
            int upb = min(nums[i]+i+1, n);
            int jump = ans[i]+1;
            for(int j=i+1; j<upb; j++) {
                if(jump < ans[j]) ans[j] = jump;
            }
        }

        return ans[n-1];
    }
};