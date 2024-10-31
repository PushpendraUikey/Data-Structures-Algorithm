#include<bits/stdc++.h>
using namespace std;

/*
Algorithm checks whether the BST contains two elements whose sum equals to a given value
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

void inorder(BinaryTreeNode<int>* root, vector<int>& ans){
    if(root==NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> res;
    inorder(root, res);
    int i = 0; int j = res.size()-1;
    while(i<j){
        int ans = res[i]+res[j];
        if(ans == target) return true;
        if(ans<target){
            i++;
        }else{
            j--;
        }
    }
    return false;
}