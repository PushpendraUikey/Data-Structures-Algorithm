#include<bits/stdc++.h>
using namespace std;

// Algorithm to find the predecessor and successor of a given node

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{   
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int x)
    {
        // Your code goes here
        Node* temp = root;
        Node* pred = nullptr;
        
        /// This one finds the predecessor

        while(temp){
            if(temp->key < x){  /// when nodes matches(i.e. key == x) then it first go to the left then find the max of that 
                                /// subtree, i.e. go right(till reaches null) bcz that's the one which comes just before 
                pred = temp;        // potential predecessor
                temp = temp -> right;  // Searching for next greater ele than curr node if it exists then that will be next potent predec
            }else{
                temp = temp -> left;
            }
        }
        
        pre = pred;
        
        pred = nullptr;
        temp = root;
        
        /// This one finds the successor

        while(temp){
            if(temp->key > x){
                pred = temp;        //// Potential Successor
                temp = temp -> left;    // Searching for is there more smaller than given key if it is that will be next potent succesr
            }else{
                temp = temp -> right;
            }
        }
        
        suc = pred;
    }
};