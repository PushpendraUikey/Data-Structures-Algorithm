/*
Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i;
        for(i=0; i<k; i++){
            pq.push(nums[i]);
        }
        for(; i<nums.size(); i++){
            if( nums[i] > pq.top() ){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};