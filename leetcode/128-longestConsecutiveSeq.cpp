#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end());
            int maxseq = 0;

            for(auto num : numSet) {
                if(numSet.find(num) != numSet.end()){
                    int cnt = 1;
                    int val = num;
                    while(numSet.find(val+1) != numSet.end()){
                        cnt++;
                        val++;
                    }

                    if(cnt > maxseq) maxseq = cnt;
                }
            }

            return maxseq;
        }
};
