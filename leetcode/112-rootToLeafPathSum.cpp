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
    pair<bool, int> hasit(TreeNode* root, int tsum, int csum){
        if(!root) return {false, 0};

        int ucsum = csum + root->val;
        if(!root->left && !root->right && tsum == ucsum) return {true, 0};
        
        pair<bool, int> leftr = hasit(root->left, tsum, ucsum);
        if(leftr.first) return leftr;
        
        pair<bool, int> rightr = hasit(root->right, tsum, ucsum);
        if(rightr.first) return rightr;

        return {false, 0};
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasit(root, targetSum, 0).first;
    }
};