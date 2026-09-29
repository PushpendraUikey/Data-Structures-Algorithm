#include <bits/stdc++.h>
using namespace std;

/*
We're completely discarding the idea of finding the pivot in the first place, bcz array contains
duplicate values and we can't be sure where pivot lies. 
So the idea is to do a binary search according to which sorted half the current mid lies, then 
followed by checking if the target lies in that sorted half or not.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int b = 0;
        int e = n-1;
        while(b <= e){
            int m = b + (e-b)/2;

            if(nums[m] == target) return true;

            if(nums[m] == nums[b] && nums[m] == nums[e]){
                b++;
                e--;
            }
            // left half perfectly sorted
            else if(nums[b] <= nums[m]) {
                // Target strictly within the left half
                if(nums[b] <= target && target < nums[m]){
                    e = m - 1;
                } else {
                    b = m + 1;
                }
            }
            // right half perfectly sorted
            else {
                // Target strictly within the right half
                if(nums[m] < target && target <= nums[e]){
                    b = m + 1;
                } else {
                    e = m - 1;
                }
            }
        }
        
        return false;
    }
};