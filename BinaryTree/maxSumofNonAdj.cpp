#include<bits/stdc++.h>
using namespace std;

/*
Here it is the code to find maximum sum of non adjacent nodes
Solution is bit tricky, hence dry run is suggested
*/
struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution{

    pair<int, int> solve(Node* root){
        /// base case
        if(root == NULL){
            return {0, 0};
        }
        pair<int, int> leftans = solve(root->left);
        pair<int, int> rightans = solve(root -> right);
        
        pair<int,int> res;
        res.first = root->data +leftans.second + rightans.second;
        res.second = max(leftans.first, leftans.second) + max(rightans.second, rightans.first);
        
        return res;
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};