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

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            if(n == 0) return 0;
            sort(nums.begin(), nums.end());

            // Handling the duplicates;
            int i = 1;
            int j = 1;
            while(i<n) {
                if(nums[i] == nums[i-1]) {
                    i++;
                }else{
                    nums[j] = nums[i];
                    i++;
                    j++;
                }
            }

            int maxseq = 1;
            for(int i=1; i<j; i++) {
                if(nums[i] == nums[i-1]+1) {
                    int cnt = 1;
                    while(i<j && nums[i] == nums[i-1]+1) {
                        cnt++;
                        i++;
                    }
                    if (cnt > maxseq) maxseq = cnt;
                }
            }

            return maxseq;
        }
};