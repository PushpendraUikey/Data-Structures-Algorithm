#include<bits/stdc++.h>
using namespace std;

/*
We're flattening the Binary Tree in sorted order by first taking inorder then
creating nodes. 
One alternative approach could be the Morris Traversal, if we donot need the 
flatten tree in sorted order.
*/
    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void inorder(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    inorder(root, ans);
    int n = ans.size();
    TreeNode<int> * newroot = new TreeNode<int>(-1);
    TreeNode<int> * curr = newroot;

    for(int i=0; i< n; i++){
        TreeNode<int> * temp = new TreeNode<int>(ans[i]);
        curr->right = temp;
        curr = temp;
    }
    return newroot->right;
}