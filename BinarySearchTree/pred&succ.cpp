#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find the predecessor and successor 
of a given node
*/
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int, int> ans;
    int pred = -1;
    int succ = -1;
    TreeNode* temp = root;

    while(temp != NULL && temp-> data != key){
        if(temp->data > key){
            succ = temp -> data;
            temp = temp -> left;
        }
        else{
            pred = temp -> data;
            temp = temp -> right;
        }
    }
    
    if(temp == NULL){
        ans.first = pred;
        ans.second = succ;
        return ans;
    }

    // Pred
    TreeNode* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;// leftsubtree ka sabse right wala predecessor hai
    } 

    // Succ
    TreeNode* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;// rightsubtree ke sabse left wala pahla succ hai
    } 
    ans.first = pred;
    ans.second = succ;
    return ans;
}