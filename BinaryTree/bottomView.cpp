#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;


/// @brief Following is the code to generate a bottom view of Binary Tree
/// Algorithm Uses BFS and 'horizontal distnace' concept to solve problem

class Solution {
  public:
    vector <int> bottomView(Node *root) {
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
    
            
            topNode[hd] = frontNode->data;              //// for each 'hd' keep track of bottom-most element of tree
            
    
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