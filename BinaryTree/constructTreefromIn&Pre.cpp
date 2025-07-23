#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Following here is the algorithm to build the tree from inorder and preorder traversal of tree
Since preorder first visits the root node, so we start building from first index of preorder
Inorder divides the tree into two parts of tree, left and right, accordingly we decide our span
to build the tree's left and right subtree.
*/

///// We are using the inorder traversals to restrict ourselves(or our recursion) to go in parti left or right

class Solution{
    int findPos(int in[], int e, int n){
        for(int i=0; i<n; i++){
            if(in[i] == e) return i;
        }
        return -1;
    }
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderend, int n){
        if(index >= n || inorderStart > inorderend){
            return nullptr;
        }
        int e = pre[index++];
        Node* root = new Node(e);
        int pos = findPos(in, e, n);   
        
        root -> left = solve(in, pre, index, inorderStart, pos-1, n );
        root -> right = solve(in, pre, index, pos+1, inorderend, n);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderindex = 0;
        Node* ans = solve(in, pre, preOrderindex, 0, n-1, n);
        return ans;
    }
};


///////////// Solution 2


class Solution{
    void findPos(int in[], map<int, int> & mp, int n){
        for(int i=0; i<n; i++){
            mp[in[i]] = i;
        }
    }
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderend, int n, map<int, int> &mp){
        if(index >= n || inorderStart > inorderend){
            return nullptr;
        }
        int e = pre[index++];
        Node* root = new Node(e);
        int pos = mp[e];
        
        root -> left = solve(in, pre, index, inorderStart, pos-1, n, mp );
        root -> right = solve(in, pre, index, pos+1, inorderend, n, mp);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderindex = 0;
        map<int, int> nodeToIndex;
        findPos(in, nodeToIndex, n);
        Node* ans = solve(in, pre, preOrderindex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};