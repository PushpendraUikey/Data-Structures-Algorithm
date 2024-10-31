#include<bits/stdc++.h>
using namespace std;

/*
We've to construct a Binary Tree from preOrder Traversal of Tree
Since preorder gives root-left-right, if the current val comes into 
correct range then a node is formed and we proceed with the algorithm
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
    
TreeNode* solve(vector<int>& preOrder, int mini, int maxi, int&i){
    if(i>=preOrder.size()){
        return nullptr;
    }
    if(preOrder[i] < mini || preOrder[i] > maxi){       //// Not in correct range then return
        return nullptr;
    }

    TreeNode* root = new TreeNode(preOrder[i++]);
    root->left = solve(preOrder, mini, root->data, i);
    root->right = solve(preOrder, root->data, maxi, i);
    return root;
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preOrder, mini, maxi, i);
}