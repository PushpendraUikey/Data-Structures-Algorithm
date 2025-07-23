#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Here's one BFS and one optimized(recursive) solution to get the left view of tree*/

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int, int> nodes;
    queue< pair<BinaryTreeNode<int>*,int>> q;
    q.push({root, 0});

    while(!q.empty()){
        pair<BinaryTreeNode<int>*,int> temp = q.front();
        q.pop();

        BinaryTreeNode<int>* frontNode = temp.first;
        int lvl = temp.second;

        if(nodes.find(lvl)==nodes.end()){
            nodes[lvl] = frontNode->data;
        }
        if(frontNode->left){
            q.push({frontNode->left, lvl + 1});
        }
        if(frontNode->right){
            q.push({frontNode->right, lvl + 1});
        }
    }
    for(auto & i: nodes){
        ans.push_back(i.second);
    }
    return ans;
}

//////////////// here is a little optimized code for left view of a binary tree

void solve(BinaryTreeNode<int>* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // since left is getting called first hence, we'll see a left view
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    int level = 0;

    solve(root, ans, level);
    return ans;
}