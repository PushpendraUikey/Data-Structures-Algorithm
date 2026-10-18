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
    public:
        int maxPathSum(TreeNode* root) {
            int maxSum = INT_MIN;
            maxGain(root, maxSum);
            return maxSum;
        }
    private:
        int maxGain(TreeNode* node, int& maxSum) {
            if (node == nullptr) return 0;
            // Recursively call maxGain on left and right children
            int leftGain = max(maxGain(node->left, maxSum), 0); //
            int rightGain = max(maxGain(node->right, maxSum), 0);
            // Current path sum including the current node
            int currentPathSum = node->val + leftGain + rightGain;
            // Update maxSum if currentPathSum is greater
            maxSum = max(maxSum, currentPathSum);
            // Return the maximum gain if we continue the same path
            return node->val + max(leftGain, rightGain);
        }
};