#include<bits/stdc++.h>
using namespace std;

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
void solve(BinaryTreeNode<int> *root, int t, int k, vector<int> &nodes, int &ans){
    if(root == NULL){
        return ;
    }
    nodes.push_back(root->data);
    /// left check
    solve(root->left, t, k, nodes, ans);

    /// right check
    solve(root->right, t, k, nodes, ans);

    if(root->data == t){
        int size = nodes.size();
        if(k>=size){    // kth ancestor do not exists
            return;
        }else{          // kth ancestor exists
            ans = nodes[size-k-1];
            return;
        }
    }
    nodes.pop_back();   // backTrack because we don't wanna mess up with right tree's ancestor with left tree's ancestor
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    vector<int> nodes;
    int ans = -1;
    solve(root, targetNodeVal, k, nodes, ans);
    return ans;
}


///////// Here is the more optimized approach to the problem

BinaryTreeNode<int> * solve(BinaryTreeNode<int> *root, int t, int &k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == t){
        return root;
    }

    /// left check
    BinaryTreeNode<int> * leftans = solve(root->left, t, k);

    /// right check
    BinaryTreeNode<int> * rightans = solve(root->right, t, k);

    // once kth ancestor is found, we don't want to process it again
    if(leftans != NULL && rightans == NULL){
        k--;
        if( k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans == NULL && rightans != NULL){
        k--;
        if (k <= 0) {
            k = INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    BinaryTreeNode<int> * ans = solve(root, targetNodeVal, k);
    if(ans != NULL && ans->data != targetNodeVal){  // It might be possible as well that the current node has the target value
        return ans->data;
    }
    return -1;
}