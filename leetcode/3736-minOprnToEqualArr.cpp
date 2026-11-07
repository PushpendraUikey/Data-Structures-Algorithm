#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxele = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for (int i=0; i<nums.size(); i++) {
            moves += abs(maxele - nums[i]);
        }
        return moves;
    }
};