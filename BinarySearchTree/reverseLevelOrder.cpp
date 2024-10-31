#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find reverse level order traversal
*/
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 


void solve(Node* root, map<int, vector<int>> &ans, int i){
    if(root == NULL) return;
    ans[i].push_back(root->data);
    
    solve(root->left, ans, i-1);
    solve(root->right, ans, i-1);
}
vector<int> reverseLevelOrder(Node *root)
{
    map<int, vector<int>> ans;
    int i =0;
    solve(root, ans, i);
    
    vector<int> fin;
    
    for(auto& it : ans){
        for(auto &val:it.second){
            fin.push_back(val);
        }
    }
    
    return fin;
}