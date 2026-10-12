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


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        int md = INT_MAX;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(!q.empty()) {
            auto [tnode, cd] = q.front();
            q.pop();

            // if it is a leaf node then it is guaranteed to be the min depth if it is encountered 
            // first time in the Level Order Traversal.
            if(!tnode->left && !tnode->right && cd<md) {
                md = cd;
            }

            if(tnode->left){
                q.push({tnode->left, cd+1});
            }
            if(tnode->right){
                q.push({tnode->right, cd+1});
            }

        }

        return md;
    }
};