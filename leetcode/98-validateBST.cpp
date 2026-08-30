#include <bits/stdc++.h>
using namespace std;

// We've used Inorder Traversal approach to validate the BST.

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    bool validation(TreeNode* root, long& prev) {
        if(!root) return true;

        bool leftv = validation(root->left, prev);
        if(!leftv) return false;
        int v = root->val;
        if(v > prev) prev = v;
        else return false;
        bool rightv = validation(root->right, prev);
        if(!rightv) return false;

        return true;
    }
public:
    bool isValidBST(TreeNode* root)  {
        long v = LONG_MIN;
        return validation(root, v);
    }
};