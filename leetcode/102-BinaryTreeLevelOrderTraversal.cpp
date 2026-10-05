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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!node){
                if(temp.empty()) break;
                q.push(nullptr);
                ans.push_back(temp);
                temp.clear();
                continue;
            }else{
                temp.push_back(node->val);
            }

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }

        return ans;
    }
};