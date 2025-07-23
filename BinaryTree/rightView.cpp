#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Following here is the algorithm to find the right view of a Binary Tree
same as left view but just we visit the right subtree first in recursive
and if you want BFS then update the hash table for each level every time 
if left inserted first
*/

/// Recursive optimized solution of right view of Binary tree;
 
void solve(BinaryTreeNode<int>* root, vector<int>&ans, int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
    
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    int level = 0;
    solve(root, ans, level);
    return ans;
}