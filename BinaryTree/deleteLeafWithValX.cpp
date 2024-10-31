#include<bits/stdc++.h>
using namespace std;

/*
Following here is the algorithm to delete a leaf node with 
value 'X'. There can be multiple instances of X in the tree*/
template <typename T>
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };



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