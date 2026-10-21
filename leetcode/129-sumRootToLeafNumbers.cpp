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
    private:
        int sumRootToLeaf(TreeNode* root, int currentSum) {
            if (!root) return 0;

            currentSum = currentSum * 10 + root->val;

            if (!root->left && !root->right) {
                return currentSum;
            }

            return sumRootToLeaf(root->left, currentSum) + sumRootToLeaf(root->right, currentSum);
        }
    public:
        int sumNumbers(TreeNode* root) {
            return sumRootToLeaf(root, 0);
        }
};