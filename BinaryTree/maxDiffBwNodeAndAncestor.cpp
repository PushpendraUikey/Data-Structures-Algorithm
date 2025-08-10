#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Given a Binary Tree, you need to find the maximum value which you can get by subtracting the 
value of node B from the value of node A, where A and B are two nodes of the binary tree and 
A is an ancestor of B.
*/

class Solution {
    int maxidiff=-1;
    int maxi=-1;
    void solve(Node* root){
        if(!root) return;
        maxidiff = max(maxidiff, maxi-root->data);
        int tem = maxi;
        if(maxi<root->data){
            tem = maxi;
            maxi = root->data;
        } 
        solve(root->left);
        solve(root->right);
        maxi = tem;
    }
  public:
    int maxDiff(Node* root) {
        // min two nodes are there in the tree.
        if(root->left) maxidiff = root->data - (root->left)->data;
        else maxidiff = root->data - (root->right)->data;
        maxi = root->data;
        solve(root->left);
        solve(root->right);
        
        return maxidiff;
    }
};