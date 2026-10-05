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
    bool sym(TreeNode* l, TreeNode* r) {
        if(!l && !r) return true;
        if(!l || !r) return false;

        if(l->val != r->val) return false;
        bool inside = sym(l->right, r->left);
        bool outside = sym(l->left, r->right);
        return inside && outside;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return right;
        return sym(root->left, root->right);
    }
};