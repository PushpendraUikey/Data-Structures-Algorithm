#include<bits/stdc++.h>
using namespace std;

/*
Algorithm finds the Lowest Common Ancestor in a BST
*/
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    while(root!=NULL){
        if((P->data < root->data) && (Q->data < root->data)){
        return LCAinaBST(root->left, P, Q);
        }
        if((P->data > root->data) && (Q->data > root->data)){
            return LCAinaBST(root->right, P, Q);
        }
        else {
            return root;
        }
    }  
    return nullptr;
}