#include<bits/stdc++.h>
using namespace std; 
    
/*
Algorithm checks if the given Binary Tree is a valid Binary Search Tree or not
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

bool solve(BinaryTreeNode<int> * root, int min, int max){
    if(root == NULL) return true;

    if(root -> data > min && root->data < max){
        bool left = solve(root->left, min, root->data);
        bool right = solve(root->right, root->data, max);

        return (right && left);
    }else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    return solve(root, INT_MIN, INT_MAX);
}

//// There is another solution as well, where recursively check if the 
/// property of tree holds or not.