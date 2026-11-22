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

public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int maxlen = max(solveincr(nums), solvedecr(nums));
        return maxlen;
    }
};