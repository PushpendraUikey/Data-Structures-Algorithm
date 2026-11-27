#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int score = INT_MAX;
        // we'll check for 3 exhaustive cases
        // case 1: first two change.
        score = min(score, nums[n-1] - nums[2]);

        // case 2: last two change.
        score = min(score, nums[n-3] - nums[0]);

        // case 3: first and last change
        score = min(score, nums[n-2] - nums[1]);

        return score;
    }
};


class Solution2 {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0; i<3; i++) {
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);
        }

        for(int i=3; i<n; i++) {
            if(nums[i] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
            if(nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        int b1, b2, b3;
        b3 = maxHeap.top(); maxHeap.pop();
        b2 = maxHeap.top(); maxHeap.pop();
        b1 = maxHeap.top(); maxHeap.pop();

        int l1, l2, l3;
        l3 = minHeap.top(); minHeap.pop();
        l2 = minHeap.top(); minHeap.pop();
        l1 = minHeap.top(); minHeap.pop();
        
        int score = INT_MAX;
        // case 1: delete first 2
        score = min(score, l1-b3);
        // case 2: delete last 2
        score = min(score, l3-b1);
        // case 3: delete first and last one each
        score = min(score, l2-b2);
        return score;
    }
};