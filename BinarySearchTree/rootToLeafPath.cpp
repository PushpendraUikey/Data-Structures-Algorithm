#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find all paths from root to leaf.
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


//// The code is to find all the paths from root to leaf.

class Solution {
    void solve(Node* root, vector<vector<int>>& ans, vector<int>& res){
        /// I want to return from the leaf node only.

        if(root->left == nullptr && root->right == nullptr){
            res.push_back(root->data);
            ans.push_back(res);
            res.pop_back(); /// since we have finished the path now remove 
                /// the path from res, to check the other paths from prev
                /// node.
            return;
        }
        /// going through "root"
        res.push_back(root->data);
        if(root->left) solve(root->left, ans, res);
        if(root->right) solve(root->right, ans, res);
        res.pop_back();/// all the path from possible from root exhausted
            //// then remove that path(data) from result vect.
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> res;
        
        solve(root, ans, res);
        
        return ans;
    }
};