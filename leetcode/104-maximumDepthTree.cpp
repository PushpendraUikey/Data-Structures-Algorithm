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
    void depth(TreeNode* root, int cd, int&md){
        if(!root) return;
        depth(root->left, cd+1, md);
        if(cd > md){
            md = cd;
        }
        depth(root->right, cd+1, md);
    }
public:
    int maxDepth(TreeNode* root) {
        int md = 0;
        depth(root, 1, md);
        return md;
    }
};