#include<bits/stdc++.h>
using namespace std;

/*
We're finding all the paths whose sum equals a given value in Binary Tree*/
template < typename T> 
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

void solve(BinaryTreeNode<int> *root, int k, vector<vector<int>> &ans, vector<int> &path){
    /// Base Case
    if(root == NULL) return;
    path.push_back(root->data);

    /// left 
    solve(root->left, k, ans, path);
    solve(root -> right, k, ans, path);

    vector<int> sol;
    int size = path.size();
    int sum = 0;
    for(int i=size-1; i>= 0; i--){
        sum+=path[i];
        if(sum == k){
            for(int j = i; j<size; j++){
                sol.push_back(path[j]);
            }
        }
    }
    if(!sol.empty()){
        ans.push_back(sol);
    }
    path.pop_back();    // here come's the backTracking, when we're done we just remove the last element from path.
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    solve(root, k, ans, path);
    return ans;
}
