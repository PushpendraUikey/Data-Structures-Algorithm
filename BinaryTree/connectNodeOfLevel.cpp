#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Given a binary tree, connect the nodes that are at the same level. You'll be given an addition 
nextRight pointer for the same.
Initially, all the next right pointers point to garbage values. Your function should set these 
pointers to the point next right for each node.
*/

class Solution {
  public:
    // Function to connect nodes at same level.
    Node* connect(Node* root) {
        Node* tmp = nullptr;
        Node* next = nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int count = q.size();
            tmp = q.front(); q.pop();
            for(int i=1; i<count; i++){
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                
                next = q.front(); q.pop();
                tmp->nextRight = next;
                tmp = next;
            }
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            tmp->nextRight = nullptr;
        }
        
        return root;
    }
};