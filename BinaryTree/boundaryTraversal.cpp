#include<bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Following is the code to do boundary traversal of a Binary Tree
*/

void leftTraverse(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL || (root->right==NULL && root->left == NULL)){
        return;
    }
    ans.push_back(root->data);

    if(root->left){
        leftTraverse(root->left, ans);
    }
    else {
        leftTraverse(root->right, ans);
    }
}
void rightTraverse(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL || (root->right==NULL && root->left == NULL)){
        return;
    }
    if(root->right){
        rightTraverse(root->right, ans);
    }
    else {
        rightTraverse(root->left, ans);
    }
    ans.push_back(root->data);          // We've to go bottom to up in the right-subtree
}
void leafTraverse(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL) return;
    if(root->right==NULL && root->left == NULL){
        ans.push_back(root->data);      //// got the leaf
        return;
    }
    leafTraverse(root->left, ans);
    leafTraverse(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);

    /// left traversal
    leftTraverse(root->left, ans);  // explore left-most part of tree

    //// leaf traversal
    leafTraverse(root->left, ans);  //// explore left subtree leaves
    leafTraverse(root->right, ans); //// explore right subtree leaves

    // right traversal
    rightTraverse(root->right, ans); // explore right-most part of tree
    
    return ans;

}