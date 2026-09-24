#include <bits/stdc++.h>
using namespace std;

class Solution {

    void solve(vector<vector<int>>&ans, vector<int>&cur, int n, int k, int idx){

        if(k==0) {
            ans.push_back(cur);
            return;
        }
        
        // If remaining number are less than k, we cannot form a combination
        if (n - idx + 1 < k) return;

        cur.push_back(idx);
        solve(ans, cur, n, k-1, idx+1);
        cur.pop_back();
        solve(ans, cur, n, k, idx+1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;

        solve(ans, cur, n, k, 1);

        return ans;
    }
};