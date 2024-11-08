#include<bits/stdc++.h>
using namespace std;

//// We are taking advantage of it already a CBT and since we need N < L && N < R to be minHeap
//// and question asks if all the left subtree has to have lesser value than right subtree then
//// we pose another condition in it  N < L < R 
//// this is "preOrder" traversal

template <typename T>
    class BinaryTreeNode 
    {
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

void inorder(BinaryTreeNode<int> * root, vector<int> &ans){
    if(root == NULL) return;
    
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
    
}
void preorderInsert(vector<int>&ans, int& i, BinaryTreeNode<int>* root){
    if(root==nullptr) return;
    if(i>=ans.size()) return;

    root->data = ans[i++];
    preorderInsert(ans, i, root->left);
    preorderInsert(ans, i, root->right);
}


BinaryTreeNode<int>* bstToMinHeap(BinaryTreeNode<int>* root) 
{
    vector<int> ans;
    inorder(root, ans);

    if(ans.empty()) return nullptr;

    int i=0;
    preorderInsert(ans, i, root);

    return root;

}