#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Here's the code to find the maximum width of a Binary Tree
it uses a BFS approach to find the maxWidth of tree
*/

int getMaxWidth(TreeNode<int> *root)
{   
    if(root == NULL) return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    int maxi = 0; int currmaxi = 0;

    while(!q.empty()){
        TreeNode<int> * temp = q.front();
        q.pop();
        currmaxi++;

        if(temp == NULL){
            maxi = max(currmaxi, maxi);
            currmaxi = 0;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(temp->left){
                q.push(temp->left);
            } 
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
    return maxi-1;
}