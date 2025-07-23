#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;
   
/*
Algorithm to count leaf nodes,
very easys just do a traversal and when hit a leaf node increment the 
answer
*/

void solve(BinaryTreeNode<int> *root, int &ans){
    if(root == NULL){
        return;
    }
if(root->left == NULL && root->right == NULL){
        ans++;
        return;
    }
    solve(root->left, ans);

    
    solve(root->right, ans);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int ans = 0;
    solve(root, ans);
    return ans;
}