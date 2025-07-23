#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Following here is the algorithm to find the diameter of tree
Diameter of a tree is the maximum distance between two nodes in 
the given tree
*/

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
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

////////////// Given here is unoptimized solution for binary tree diameter calculation.

class Solution {
    int height(struct Node* node){
        if(node == NULL) return 0;
        
        int left = height(node->left);
        int right = height(node ->right); 
        
        int ans = max(left, right) + 1;
        
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL) return 0;
        
        int op1 = diameter(root->left);
        int op2 = diameter(root -> right);
        int op3 = height(root->left) + height(root->right) + 1;
        
        int ans = max(op1, max(op2, op3));
        return ans;
    }
};

//////////// Here is optimized way to get diameter, i.e. good way to get two value from the same solution


class Solution {
    pair<int, int> diameterfast(Node* root){
        if(root == NULL){
            pair<int, int> ans = make_pair(0,0);
            return ans;
        }
        
        pair<int, int> left = diameterfast(root->left);
        pair<int, int> right = diameterfast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL) return 0;
        
        pair<int, int> ans = diameterfast(root);
        
        return ans.first;
    }
};


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}