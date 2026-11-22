#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solveincr(vector<int>&nums){
        int n = nums.size();
        int maxlen = 1;
        int right = 1;
        int left  = 0;

        while(right < n) {
            while(right < n && nums[right] > nums[right-1]) right++;
            maxlen = max(maxlen, right-left);
            left = right;
            right++;
        }

        return maxlen;
    }

    int solvedecr(vector<int>&nums){
        int n = nums.size();
        int maxlen = 1;
        int right = 1;
        int left  = 0;

        while (right < n) {
            while(right < n && nums[right] < nums[right-1]) right++;
            maxlen = max(maxlen, right-left);
            left = right;
            right++;
        }

        return maxlen;
    }

    int solve(vector<int>&nums) {
        int n = nums.size();
        int inc=1, dec=1, best=1;
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                inc++;
                dec=1;
            }
            else if(nums[i] < nums[i-1]) {
                dec++;
                inc=1;
            }
            else {
                inc=1;
                dec=1;
            }
            best = max(best, max(inc, dec));
        }
        return best;
    }

public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        
        int maxlen = max(solveincr(nums), solvedecr(nums));
        return maxlen;
    }
};