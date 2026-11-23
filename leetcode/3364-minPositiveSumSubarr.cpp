#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>&nums, int ssize) {
        int minsum = INT_MAX;
        int currsum = 0;
        for(int i=0; i<ssize; i++){
            currsum += nums[i];
        }

        if(currsum > 0) minsum = currsum;

        for(int i=ssize; i<nums.size(); i++) {
            currsum = currsum - nums[i-ssize] + nums[i];
            if(currsum > 0) minsum = min(minsum, currsum);
        }

        return minsum;
    }
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minsum = INT_MAX;
        for(int i=l; i<=r; i++){
            minsum = min(minsum, solve(nums, i));
        }

        return minsum == INT_MAX ? -1 : minsum;
    }
};

class Solution2 {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int size = nums.size();
        int minsum = INT_MAX;
        int currsum = 0;
        int windowsum = 0;

        for(int i=0; i<l; i++){
            currsum += nums[i];
        }
        if (currsum > 0) minsum = currsum;
        windowsum = currsum;

        for(int i=l; i<r && i<size; i++){
            windowsum += nums[i];
            if(windowsum > 0) minsum = min(minsum, windowsum);
        }

        for(int i=l; i<size; i++) {
            currsum = currsum - nums[i-l] + nums[i];
            if(currsum > 0) minsum = min(minsum, currsum);
            int j=i+1;
            windowsum = currsum;
            while(j<i+r-l+1 && j<size){
                windowsum += nums[j];
                if(windowsum > 0) minsum = min(minsum, windowsum);
                j++;
            }
        }

        return minsum == INT_MAX ? -1 : minsum;
    }
};