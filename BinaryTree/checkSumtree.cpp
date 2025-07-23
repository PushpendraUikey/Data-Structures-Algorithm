#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Code to check if the given Binary Tree is sum tree or not
A given tree is sumTree if it current root's value is sum of it's leftsubtree's sum and it's right
subtree's sum
*/

pair<bool, int> isSumTreefast(TreeNode<int> *root){
    if(root==NULL){
      return { true, 0 };
    }
    if(root->left == NULL && root->right == NULL){
      return { true, root->val };
    }
    pair<bool, int> leftans = isSumTreefast(root->left);
    pair<bool, int> rightans = isSumTreefast(root->right);
    bool condn = root->val == leftans.second + rightans.second;

    pair<bool, int> ans;
    if( leftans.first && rightans.first && condn){
        ans.first = true;
    }else{
        ans.first = false;
    }
    ans.second = root->val + leftans.second + rightans.second;
    return ans;
}
bool isSumTree(TreeNode<int> *root)
{
    return isSumTreefast(root).first;
}