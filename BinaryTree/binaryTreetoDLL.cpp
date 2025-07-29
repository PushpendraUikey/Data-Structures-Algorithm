#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

// Following inorder traversal to convert to DLL
// Simple idea, the head of DLL is going to come from left subtree
Node* prev = nullptr;
Node* BTtoDLL(Node* root){
    if(!root) return nullptr;
    Node* head = BTtoDLL(root->left);
    if(!prev){
        head = root;
    }else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTtoDLL(root->right);
    return head;
}

// Solution with extra O(n) space.
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    vector<Node*> res;
    void sol(Node *root)
    {
        if(root==NULL) return;
        sol(root->left);
        res.push_back(root);
        sol(root->right);
    }
    Node * bToDLL(Node *root)
    {
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL) return root;
        res.clear();
        sol(root);
        int i = 0;
        res[i]->left=NULL;
        res[i]->right = res[i+1];
        for(i = 1; i<res.size()-1; i++)
        {
            res[i]->left=res[i-1];
            res[i]->right = res[i+1];
        }
        res[i]->left=res[i-1];
        res[i]->right = NULL;
        return res[0];
    }
};