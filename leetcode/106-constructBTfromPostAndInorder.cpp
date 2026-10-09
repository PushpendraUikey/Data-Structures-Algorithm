#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
    TreeNode* build(vector<int>& postorder, unordered_map<int,int>&mp, int& idx, int ib, int ie) {
        if (ib > ie) {
            idx++;
            return nullptr;
        }
        int val = postorder[idx];
        int cidx = mp[val];
        TreeNode* root = new TreeNode(val);

        // Though the ranges are according to the inorder traversal, still we build the right subtree first
        // bcz the postorder traversal is in the order of left, right, root. 
        idx--;
        root->right = build(postorder, mp, idx, cidx + 1, ie);

        idx--;
        root->left = build(postorder, mp, idx, ib, cidx - 1);

        return root;
    }
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int, int> mp;
            for(int i=0; i<inorder.size(); i++) {
                mp[inorder[i]] = i;
            }
            int idx = postorder.size() - 1;
            return build(postorder, mp, idx, 0, inorder.size() - 1);
        }
};