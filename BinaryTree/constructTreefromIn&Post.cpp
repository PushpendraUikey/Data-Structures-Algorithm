#include<bits/stdc++.h>
using namespace std;

/*
Following is the algorithm to build a tree from inorder and postorder traversal of tree
Since in Postorder root is visited in the end, so we start with last indexed element
and in Inorder traversal root divides the tree into to subtree, left and right so we
also decide the span of tree accordingly
*/
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
    void findPos(int in[], map<int, int> & mp, int n){      //// To keep track of index of elements in inorder array
        for(int i=0; i<n; i++){
            mp[in[i]] = i;
        }
    }
    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderend, int n, map<int, int> &mp){
        if(index < 0 || inorderStart > inorderend){
            return nullptr;
        }
        int e = post[index--];
        Node* root = new Node(e);
        int pos = mp[e];
        
        
        root -> right = solve(in, post, index, pos+1, inorderend, n, mp);
        root -> left = solve(in, post, index, inorderStart, pos-1, n, mp);
        
        
        return root;
    }
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        int postOrderindex = n-1;
        map<int, int> nodeToIndex;
        findPos(in, nodeToIndex, n);
        Node* ans = solve(in, post, postOrderindex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};