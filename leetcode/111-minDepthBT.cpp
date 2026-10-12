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
    int md = INT_MAX;
    void depth(TreeNode* root, int cd) {
        if(!root) return;
        
        depth(root->left, cd+1);
        
        depth(root->right, cd+1);

        // count towards depth only if it is a leaf node.
        if(!root->left && !root->right && md > cd) md = cd;
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        md = INT_MAX;
        depth(root, 1);
        return md;
    }
};