#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
    pair<int, bool> balanced(TreeNode* root) {
        if(!root) return {0, true};

        pair<int, bool> leftr = balanced(root->left);
        pair<int, bool> rightr = balanced(root->right);

        if(!leftr.second || !rightr.second) return {-1, false};
        if(abs(leftr.first - rightr.first) > 1) return {-1, false};

        return {max(leftr.first, rightr.first)+1, true};
    }
public:
    bool isBalanced(TreeNode* root) {
        return balanced(root).second;
    }
};