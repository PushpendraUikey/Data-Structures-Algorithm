#include "allnodeDef.h"


/// @brief  This definition of CBT comes from the heaps, we mean that each level is filled complete except the last, and last fill's from left.
/// @param root root of binary tree
/// @param index with reference to heaps array implementation
/// @param cnt Total number of nodes;
/// @return tells whether the binary tree is complete or not.

bool isCBT(struct node* root, int index, int cnt){
        if(root == NULL) return true;
        
        if(index >= cnt) return false;
        else{
            bool left = isCBT(root->left, 2*index+1, cnt);
            bool right = isCBT(root->right, 2*index+2, cnt);
            
            return (left && right);
        }
    }