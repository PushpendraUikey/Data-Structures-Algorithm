#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int score = INT_MAX;
        // we'll check for 3 exhaustive cases
        // case 1: first two change.
        score = min(score, nums[n-1] - nums[2]);

        // case 2: last two change.
        score = min(score, nums[n-3] - nums[0]);

        // case 3: first and last change
        score = min(score, nums[n-2] - nums[1]);

        return score;
    }
};