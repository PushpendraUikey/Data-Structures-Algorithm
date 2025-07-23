#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Code to check if a binary tree is a mirror tree
i.e. left subpart is just flip copy of right subpart and viceversa
*/

bool areMirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 != NULL && root2 == NULL) return false;
    else if(root1 == NULL && root2 != NULL) return false;

    bool prev = areMirror(root1->left, root2->right);
    bool prev1 = areMirror(root1 -> right, root2 ->left);
    bool condn = root1->data == root2->data;

    if(prev && prev1 && condn){
        return true;
    }else{
        return false;
    }
}