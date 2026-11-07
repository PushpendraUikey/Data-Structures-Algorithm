#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minMoves(vector<int>& nums) {
            int n = nums.size();
            int minNum = *min_element(nums.begin(), nums.end());
            int moves = 0;

            for (int i=0; i<n; i++) {
                moves += (nums[i] - minNum);
            }

            return moves;
        }
};