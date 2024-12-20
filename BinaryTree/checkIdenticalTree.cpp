#include<bits/stdc++.h>
using namespace std;

/*
Check if two tree's are Identical or not
*/
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
    };


bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1 == NULL && root2 == NULL) return true;	 
    if(root1 != NULL && root2 == NULL) return false;	
    if(root1 == NULL && root2 != NULL) return false;	

    bool left = identicalTrees(root1->left, root2->left);   // both should reach the NULL simultaneously in order to be identical
    bool right = identicalTrees(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value){
        return true;
    }
    else return false;
}