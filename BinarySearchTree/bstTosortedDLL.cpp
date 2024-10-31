#include<bits/stdc++.h>
using namespace std;

/*
Here is the algorithm to convert a BST to a sorted DLL

Idea is start with the right most node and make it head then
start coming back(with pointers attaching appropriately) and 
then go to leftmost parts till you finish*/

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

void convertTosortedDLL(TreeNode* root, TreeNode* &head){
    // base case
    if(root == nullptr) return ;
    convertTosortedDLL(root->right, head);

    root -> right = head;

    if(head != nullptr){
        head -> left = root;
    }
    head = root;

    convertTosortedDLL(root->left, head);
   
}