#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Following here is the algorithm to delete a leaf node with 
value 'X'. There can be multiple instances of X in the tree*/

BinaryTreeNode<int>* deleteLeafNodes(BinaryTreeNode<int> *root, int x)
{
    //Write your code here
    if(root==nullptr) return nullptr;

    //// checking if leaf then delete the node
    if(root->left == nullptr && root->right == nullptr){
        if(root->data == x){
            delete root;
            return nullptr;
        }
        return root;
    }

    if(root->left) root->left = deleteLeafNodes(root->left,  x);
    if(root->right) root->right = deleteLeafNodes(root->right, x);
   

   //// after recursion if it becomes leaf then delete the node.

    if(root->left == nullptr && root->right == nullptr){
        if(root->data == x){
            delete root;
            return nullptr;
        }
        return root;
    }
    return root;
}