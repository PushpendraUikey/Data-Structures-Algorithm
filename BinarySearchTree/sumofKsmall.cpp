#include "tutorial.cpp"
/*
Algorithm here solves the problem of sum of k smallest elements in BST
*/
void solve(Node* root, int &k, int &sum){
    if(root==nullptr){
        return;
    }
    solve(root->left, k, sum);
    if(k>0){
        k--;
        sum += root->data;
    }
    solve(root->right, k, sum);
}
int sum(Node* root, int k) 
{ 
  
    // Your code here
    int sum = 0;
    solve(root, k, sum);
    return sum;
    
}