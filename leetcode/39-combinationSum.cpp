#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<vector<int>>&ans, vector<int>&curr, vector<int>&cand, int t, int start){
        if(t==0) {
            ans.push_back(curr);
            return;
        }
        if(t < 0) return;

        int n = cand.size();
        for(int i=start; i<n; i++) {
            if(t-cand[i] >= 0) {
                curr.push_back(cand[i]);
                solve(ans, curr, cand, t-cand[i], i);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, curr, candidates, target, 0);
        return ans;
    }
};