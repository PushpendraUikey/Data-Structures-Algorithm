#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to search for an element in BST
*/
    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) return false;
    if(root->data == x) return true;
    if(root->data > x) return searchInBST(root->left,  x);
    else return searchInBST( root -> right, x);
}

bool iterativeSearchInBST(BinaryTreeNode<int> *root, int x){
    BinaryTreeNode<int>* temp = root;
    while(temp){
        if(temp -> data == x) return true;
        if(temp -> data > x){   /// check in left part
            temp = temp -> left;    
        }else{                  /// check in right part 
            temp = temp -> right;
        }
    }
    return false;
}