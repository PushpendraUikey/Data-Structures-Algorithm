#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void solve(TreeNode* root, vector<vector<int>>& ans, vector<int>& tans, int tsum, int csum) {
        if(!root) return;
        csum += root->val;
        tans.push_back(root->val);

        if(!root->left && !root->right && csum == tsum) {
            ans.push_back(tans);
        }
        solve(root->left, ans, tans, tsum, csum);
        solve(root->right, ans, tans, tsum, csum);
        tans.pop_back();
    }

    public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> tans;
        solve(root, ans, tans, targetSum, 0);
        return ans;
    }
};