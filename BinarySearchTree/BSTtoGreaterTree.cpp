#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to convert a BST to greater sum tree in which
any node has value equals to sum of all the nodes left to it 
including the node itself
*/
template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };


void solve(BinaryTreeNode<int>* root, int & sum){
    if(root == nullptr) return;

    solve(root->right, sum);
    sum += root->data;
    root->data = sum;
    solve(root->left,sum);
}
BinaryTreeNode<int>* bstToGreaterTree(BinaryTreeNode<int>* root) 
{
    int sum = 0;
    solve(root, sum);
    return root;
}