#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Balanced Binary tree is a tree in which height of left subtree and right subtree 
has same height or it has a difference of one.
*/

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

///  Unoptimized solution to check if the tree is balanced or what?

class Solution{
    int height(Node * root){
        if(root == NULL){
            return 0;
        }
        int left = height(root -> left);
        int right = height(root -> right);

        int ans = max(left, right) + 1;

        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL){
        return true;
    }

    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right );

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff) return true;
    else return false;
    }
};

/// Optimized solution to check if the tree is balanced
class Solution{
        pair<bool, int> isBalancedfast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<bool, int> left = isBalancedfast(root->left);
        pair<bool, int> right = isBalancedfast(root->right);
        
        bool diff = abs(left.second-right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(left.first && right.first && diff){
             ans.first = true;
        }else{
            ans.first = false;
        }
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.

    bool isBalanced(Node *root)
    {
        if(root == NULL){
        return true;
    }

    pair<bool, int> ans = isBalancedfast(root);
    
    return ans.first;
    }
};



int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}