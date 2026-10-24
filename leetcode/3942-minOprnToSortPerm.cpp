#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& nums, int minidx, bool left) {
        int n = nums.size();
        if (left) {
            for (int i = 0; i < n - 1; i++) {
                int i1 = (i + minidx) % n;
                int i2 = (i + minidx + 1) % n;
                if (nums[i1] > nums[i2]) return false;
            }
        } else {
            for (int i = 0; i < n - 1; i++) {
                // n is added to prevent negative modulos
                int i1 = (minidx - i + n) % n;
                int i2 = (minidx - i - 1 + n) % n;
                if (nums[i1] > nums[i2]) return false;
            }
        }
        return true;
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Robust way to find the index of the minimum element
        int minidx = min_element(nums.begin(), nums.end()) - nums.begin();

        if (check(nums, minidx, true)) {
            // Either sort by left rotate or by reverse left-rotate then reverse back
            return min(minidx, 2 + (n - minidx));
        } 
        else if (check(nums, minidx, false)) {
            // Either sort by reverse left-rotate then reverse back or by left rotate.
            return min(n - minidx, 2 + minidx);
        }

        return -1; // Cannot be sorted
    }
};