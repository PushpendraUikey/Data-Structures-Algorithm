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
    TreeNode* build(vector<int>& preorder, unordered_map<int,int>&mp, int&p, int ib, int ie){
        if( ib > ie ) {
            p--;
            return nullptr;
        }

        int val = preorder[p];
        int idx = mp[val];
        int le = idx-1;
        int rs = idx+1;

        TreeNode* root = new TreeNode(val);
        if( ib <= le ){
            p++;
            root->left = build(preorder, mp, p, ib, idx-1);
        }
        if( rs <= ie ){
            p++;
            root->right = build(preorder, mp, p, idx+1, ie);
        }

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0;
        int ib = 0;
        int ie = inorder.size() - 1;
        unordered_map<int, int> mp;
        for(int i = 0; i<preorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return build(preorder, mp, p, ib, ie);
    }
};