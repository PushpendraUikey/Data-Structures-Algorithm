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
    void inorder(vector<int> &arr, TreeNode* root) {
        if(!root) return;
        inorder(arr, root->left);
        arr.push_back(root->val);
        inorder(arr, root->right);
    }
    void fillinorder(vector<int>&arr, TreeNode* root, int&i) {
        if(!root) return;
        fillinorder(arr, root->left, i);
        root->val = arr[i];
        i++;
        fillinorder(arr, root->right, i);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        int i = 0;
        inorder(arr, root);
        sort(arr.begin(), arr.end());
        fillinorder(arr, root, i);
    }
};