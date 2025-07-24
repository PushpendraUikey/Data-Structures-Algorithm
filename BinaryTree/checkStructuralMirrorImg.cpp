#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Given a binary tree, check if the tree can be folded or not. A tree can be folded if left and right 
subtrees of the tree are structure wise mirror image of each other. An empty tree is considered as foldable
*/
bool solve(Node* left, Node* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    return (solve(left->left, right->right) && solve(left->right, right->left));
}

bool IsFoldable(Node* root) {
    if(!root) return true;
    return solve(root->left, root->right);
}