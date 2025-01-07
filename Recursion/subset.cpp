#include<bits/stdc++.h>

//////////////// Solution assumes that all the elements in the given array are unique and hence finds the distinct subsets i.e. powersets

using namespace std;

class Solution {
private:
    void solve(vector<int> output, vector<int>& nums, vector<vector<int>>& ans, int i){
        if(i == nums.size()){
            ans.push_back(output);
            return;
        }

        // exclude call
        solve(output, nums, ans, i+1);

        // include call
        output.push_back(nums[i]);
        solve(output, nums, ans, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        solve(output, nums, ans, 0);
        return ans;
    }
};