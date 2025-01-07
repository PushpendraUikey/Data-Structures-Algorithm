#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int i){
        if( i >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            solve(nums, ans, i+1);
            // backtrack
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;

    solve(nums, ans, 0);
    return ans;
    }
};



////////////////// Solution 2 for strings,

void Solve(string str, vector<string> &ans, int i){
    
    // base case
    
    if(i>=str.length()){
        ans.push_back(str);
        return;
    }

    for (int j=i; j<str.length(); j++){
        swap(str[i], str[j]);
        Solve(str, ans, i+1);
        // backtrack
        swap(str[i], str[j]);
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    
    int i = 0;
    Solve(str,ans,i);

    sort(ans.begin(), ans.end());

    return ans;
}