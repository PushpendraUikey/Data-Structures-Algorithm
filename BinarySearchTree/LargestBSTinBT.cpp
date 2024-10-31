#include<bits/stdc++.h>
using namespace std;

/*
In this code we've solution of maximum Binary Search Tree in a Binary Tree
*/
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(TreeNode* root, int &ans){
    // base case
    if(root == NULL){
      return { INT_MIN, INT_MAX, true, 0 };
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    // if right&left both part are bst & current root data is smaller than minimum of right
    // and maximum of left then current portion is also a BST, mark it true
    if(left.isBST && right.isBST && (root->data < right.mini && root->data > left.maxi)){
        currNode.isBST = true;
    }else{
        currNode.isBST = false;
    }

    if(currNode.isBST){ // if current portion is also a bst then update the ans.
        ans = max(ans, currNode.size);
    }

    return currNode;
}
int largestBST(TreeNode * root){
    int maxsize = 0;
    info temp = solve(root, maxsize);

    return maxsize;
}