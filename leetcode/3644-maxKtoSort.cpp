#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int sortPermutation(vector<int>& nums, int k) {
            int n = nums.size();
            int i = 0;
            int val = -1;
            while( i < n ) {
                if(nums[i] != i) {
                    val = nums[i];
                    break;
                }
                i++;
            }

            if(val == -1) return 0;

            while(i<n) {
                if(nums[i] != i) {
                    val = val & nums[i];
                }
                i++;
            }

            return val;
        }
};