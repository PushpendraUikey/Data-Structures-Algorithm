#include<bits/stdc++.h>
using namespace std;

/*
BST to maxHeap conversion. Inorder traversal of BST gives elements in sorted order
fill the BST in postorder, it'll give MaxHeap.
*/
struct Node {
    int data;
    Node *left, *right;
};

class Solution{
    void inorder(Node* root, vector<int>& ans){
        if(root==NULL) return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    void postOrderfill(Node* root, vector<int> &ans, int &i){
        if(root==NULL) return;
        
        postOrderfill(root->left, ans, i);
        postOrderfill(root->right, ans, i); 
        root->data = ans[i++];  //// elements start filling in the tree from the leaf
                            //// which will ensure that smaller element will start filling
                            /// from left subtree and keep going up.
    }
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> ans;
        inorder(root, ans); /// inorder traversal will give the elements in sorted order.
        
        int i=0;
        postOrderfill(root, ans, i);
    }    
};