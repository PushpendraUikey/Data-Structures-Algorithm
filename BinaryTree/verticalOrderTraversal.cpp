#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Vertical order Traversal of tree, algorithm is based on BFS
*/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while(!q.empty()){
        pair<TreeNode<int>*, pair<int, int>> temp = q.front();
        q.pop();
        TreeNode<int>* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);
        if(frontNode->left){
            q.push({frontNode->left, {hd-1, lvl+1}});
        }
        if(frontNode->right){
            q.push({frontNode->right, {hd+1, lvl+1}});
        }
    }
    for(auto &i : nodes){
        for(auto &j : i.second){
            for(auto &k : j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}