#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Here is the code to get top view of a Binary Tree
Logic based on Horizontal Distance from root*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
{
    vector<int> ans;
    if(root == NULL ) return ans;

    map<int, int> topNode;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push({frontNode->left, hd-1});
        }
        if(frontNode->right){
            q.push({frontNode->right, hd+1});
        }
    }
    for(auto &i : topNode){
        ans.push_back(i.second);
    }
    return ans;
}

};