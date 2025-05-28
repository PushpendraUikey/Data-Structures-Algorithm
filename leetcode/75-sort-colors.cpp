
/*
Problem: https://leetcode.com/problems/sort-colors/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0, one=0;
        int i=0;
        for(; i<nums.size(); i++){
            if(nums[i]==0) zero++;
            else if(nums[i] == 1) one++;
        }
        i=0;
        while(zero-->0){
            nums[i++] = 0;
        }
        while(one --> 0){
            nums[i++] = 1;
        }
        while(i < nums.size()){
            nums[i++] = 2;
        }
    }
};