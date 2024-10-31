#include<bits/stdc++.h>
using namespace std;

/* 
Algorithm deletes the nodes which are out of bound in a Binary Search Tree
It has similar algorithm that of construnction of Binary Tree, just it avoids going 
out of bound, it silently donot accepts the element out of given bound
*/

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
    Node* removeLeft(Node* root, int l){
        if(root == nullptr) return nullptr;
        
        if(root->data >= l){
            root -> left = removeLeft(root->left, l);
            return root;
        }else{
            return removeLeft(root->right, l);
        }
    }
    Node* removeRight(Node* root, int r){
        if(root == nullptr) return nullptr;
        
        if(root->data <= r){
            root -> right = removeRight(root->right, r);
            return root;
        }else{
            return removeRight(root->left, r);
        }
    }
    public:
    Node* removekeys(Node* root, int l, int r) {
        root = removeLeft(root, l);
        root = removeRight(root, r);
        
        return root;
    }
};