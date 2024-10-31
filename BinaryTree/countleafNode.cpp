#include<bits/stdc++.h>
using namespace std;
   
/*
Algorithm to count leaf nodes,
very easys just do a traversal and when hit a leaf node increment the 
answer
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

void solve(BinaryTreeNode<int> *root, int &ans){
    if(root == NULL){
        return;
    }
if(root->left == NULL && root->right == NULL){
        ans++;
        return;
    }
    solve(root->left, ans);

    
    solve(root->right, ans);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int ans = 0;
    solve(root, ans);
    return ans;
}