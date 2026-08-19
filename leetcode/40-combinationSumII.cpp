#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<vector<int>>&ans, vector<int>&cur, vector<int>&cand, int t, int indx) {
        if(t==0) {
            ans.push_back(cur);
            return;
        }
        if(t < 0) return;
        int n = cand.size();
        for(int i=indx; i<n; i++) {
            if(i>indx && cand[i] == cand[i-1]) continue;
            if(t-cand[i] >= 0) {
                cur.push_back(cand[i]);
                solve(ans, cur, cand, t-cand[i], i+1);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        solve(ans, cur, candidates, target, 0);
        return ans;
    }
};