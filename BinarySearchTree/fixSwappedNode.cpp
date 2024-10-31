#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution {
    // Do inorder traversal to get elements in a increasing order.
    void inorder(struct Node* root, vector<int>&v){
        if(root == nullptr) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    // since inorder gives sorted arr, the elements which violates the rule, find them
    void findSwapped(vector<int>&arr, int& first, int& sec){
        int i=0; int j = arr.size()-1;
        bool f = true;
        bool l = true;
        while(i<j &&(f || l)){
            if(arr[i] > arr[i+1]){
                first = i;
                f = false;
            }
            if(arr[j] < arr[j-1]){
                sec = j;
                l = false;
            }
            if(f) i++;
            if(l) j--;
        }
    }
    // swap the elements by first finding them in the tree
    void solve(struct Node* root, int& f, int& l){
        if(root==nullptr) return;
        solve(root->left,f, l);
        if(root->data == f || root->data == l){
            if(root->data == f){
                root->data = l;
            }else
            {
                root->data = f;
            }
        }
        solve(root->right, f, l);
    }
  public:
    struct Node *correctBST(struct Node *root) {
        // code here
        vector<int> v;
        inorder(root, v);
        
        int first=-1;
        int last = -1;
        findSwapped(v, first, last);
        
        first = v[first];
        last = v[last];
        
        solve(root, first, last);
        return root;
    }
};