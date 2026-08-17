#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target <= nums[0]) return 0;
        auto idx = std::upper_bound(nums.begin(), nums.end(), target);
        int pos = (idx-nums.begin());
        
        if(nums[pos-1]==target) return pos-1;
        return pos;
    }
};