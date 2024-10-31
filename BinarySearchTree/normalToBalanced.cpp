#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

TreeNode<int>* inordertoBST(int s, int e, vector<int>& inorderval){
    if( s > e ) return nullptr;
    int mid = (s + e)/2;
    TreeNode<int> * root = new TreeNode<int>(inorderval[mid]);
    root->left = inordertoBST(s , mid-1, inorderval);   // make a sub-bst from [s,mid) range and attach it to left sub-bst
    root->right = inordertoBST(mid+1, e, inorderval);   // make a sub-bst from (mid, E] range and attach it to right sub-bst
    return root;
}
// Inorder traversal of Tree
void inorder(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> traversal;
    inorder(root, traversal);

    return inordertoBST(0, traversal.size()-1, traversal);
}