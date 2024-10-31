#include<bits/stdc++.h>
using namespace std;

/*
Here is the algorithm to flatten a Binary Tree using Morris Traversal in O(1)
in flattened tree left pointer will be null and right pointer will
point to next node
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

class Solution
{
    public:
    void flatten(Node *root)
    {
        // In O(1) space we do flatten the LL, using morris traversal
        
        Node* curr = root;
        
        while(curr){
            if(curr->left){
                Node* pred = curr -> left;
                while(pred -> right){
                    pred = pred -> right;
                }
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
                
            }
            curr = curr -> right;
        }
    }
};