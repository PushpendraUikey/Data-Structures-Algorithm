#include<bits/stdc++.h>
using namespace std;

/*
Here is the algorithm to convert sorted array to BST
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};

class Solution {
    Node* solve(vector<int> & nums, int i, int e){
        if(i>e) return nullptr;
        
        int m = i + (e-i)/2;
        
        Node* root = new Node(nums[m]);
        
        root -> left = solve(nums, i, m-1);
        root -> right = solve(nums, m+1, e);
        
        return root;
    }
  public:
    Node* sortedArrayToBST(vector<int>& nums) {
        int i=0; int e = nums.size()-1;
        
        return solve(nums, i, e);
    }
};