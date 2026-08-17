#include <bits/stdc++.h>
using namespace std;

class Solution {
    int binarySearch(vector<int>& nums, int t, int s, int e){
        int mid = s + (e-s)/2;
        while(s <= e){
            mid = s + (e-s)/2;
            if(nums[mid] == t) return mid;
            if(nums[mid] > t) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int b = 0;
        int e = nums.size() - 1;
        vector<int> ans;

        int curridx = binarySearch(nums, target, b, e);
        if(curridx == -1) return {-1, -1};

        int left = curridx, 
            right = curridx;
        int tl=0, tr = e-1;

        while( (tl = binarySearch(nums, target, b, left-1)) != -1){
            left = tl;
        }

        while( (tr = binarySearch(nums, target, right+1, e)) != -1){
            right = tr;
        }

        return {left, right};
    }
};