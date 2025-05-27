/*
Problem: https://leetcode.com/problems/squares-of-a-sorted-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int firstpos=0;
        for(; firstpos<nums.size(); firstpos++){
            if(nums[firstpos] >= 0){
                break;
            }
        }
        int rev = firstpos-1;
        int j=0;
        while(rev>=0 && firstpos < nums.size()){
            if(-1*nums[rev] >= nums[firstpos]){
                ans[j] = nums[firstpos] * nums[firstpos];
                firstpos++;
            }else{
                ans[j] = nums[rev]*nums[rev];
                rev--;
            }
            j++;
        }
        while(firstpos<nums.size()){
            ans[j] = nums[firstpos] * nums[firstpos];
            firstpos++;
            j++;
        }
        while( rev >= 0 ){
            ans[j] = nums[rev]*nums[rev];
            rev--;
            j++;
        }

        return ans;
    }
};