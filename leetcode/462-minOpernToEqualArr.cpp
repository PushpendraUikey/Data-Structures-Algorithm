#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int moves = 0;
        int v = n/2;
        int medval = nums[v];
        for (int i = 0; i<n; i++) {
            moves += abs(nums[i] - medval);
        }
        
        return moves;
    }
};