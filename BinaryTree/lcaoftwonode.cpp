#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Following here is the recursive approach to find the least common ancestor 
of two nodes.
*/

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL){
           return NULL;
       }
       if(root->data == n1 || root -> data == n2){
           return root;
       };
       
       Node* leftAns = lca(root->left, n1, n2);
       Node* rightAns = lca(root->right, n1, n2);
       
       if(leftAns!=NULL && rightAns != NULL){
           return root;
       }
       else if(leftAns != NULL && rightAns == NULL){
           return leftAns;
       }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }else{
            return NULL;
        }
    }
};


////////// Here is the solution for the case when, Nodes given are connected to parent nodes

BinaryTreeNode<int> *LCA(BinaryTreeNode<int> *root,int n1, int n2){
    if(root == NULL){
        return nullptr;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    BinaryTreeNode<int> *leftans = LCA(root->left, n1, n2);
    BinaryTreeNode<int> *rightans = LCA(root->right, n1, n2);

    if(leftans != NULL && rightans != NULL){
        return root;
    }else if(leftans != NULL && rightans == NULL){
        return leftans;
    }else if(leftans == NULL && rightans != NULL){
        return rightans;
    }else{
        return nullptr;
    }
}
BinaryTreeNode<int> *leastCommonAncestor(BinaryTreeNode<int> *n1, BinaryTreeNode<int> *n2)
{  
    if(n1 == NULL) return n2;
    if(n2== NULL) return n1;
    BinaryTreeNode<int>* temp = n1;

    /// Finding the root
    while(temp->parent != NULL){
        temp = temp->parent;
    }
    BinaryTreeNode<int> *ans = LCA(temp, n1->data, n2->data);
    return ans;
}