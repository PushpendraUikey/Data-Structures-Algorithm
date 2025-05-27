/*
Problem: https://leetcode.com/problems/single-number/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        int i=0;
        for(; i< nums.size(); i++){
            x ^= nums[i];
        }

        return x;
    }
};