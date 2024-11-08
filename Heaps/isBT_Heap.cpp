#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to check if the Binary Tree is a Heap or not.
*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {

    /// @brief Counting the nodes in this particular function
    /// @param root 
    /// @return 
    int countNodes(struct Node* root){
        if (root == NULL) return 0;
        int ans = 1 + countNodes(root->left) + countNodes(root->right);

        return ans;
    }

    /// if at any point index exceeds the total nodes, i.e. it's right subtree is filled first and left
    /// subtree is empty which violates the fact for CBT, which in turns fail to be heap.

    bool isCBT(struct Node* root, int index, int cnt){
        if(root == NULL) return true;
        
        if(index >= cnt) return false;
        else{
            bool left = isCBT(root->left, 2*index+1, cnt);
            bool right = isCBT(root->right, 2*index+2, cnt);
            
            return (left && right);
        }
    }
    
    // Once we checked that it is CBT, we have to check for whether we are able to 
    // let it be a max heap or not.
    
    bool isMaxorder(struct Node* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->right == NULL) {
            return (root->data > (root->left)->data);
        }else{
            bool left = isMaxorder(root->left);
            bool right = isMaxorder(root->right);
            
            return (left && right && (root->data > (root->left)->data  && root->data > (root->right)->data));
        }
    }
  public:
    bool isHeap(struct Node* root) {
        int index = 0;
        int totalCount = countNodes(root);
        
        if(isCBT(root, index, totalCount) && isMaxorder(root)){
            return true;
        }
        return false;
    }
};