//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
class Solution{
    pair<bool, int> isBalancedfast(Node* root, int currentlevel, int & leaflevel){
        if(root == NULL){
            return {true, 0};
        }
        ///// Reached the leaf
        if(root->right ==NULL && root->left == NULL){
            if(leaflevel == -1){
                leaflevel = currentlevel;
            }
            bool isAtsamelevel = (currentlevel == leaflevel);
            
            return {isAtsamelevel, currentlevel};
        }
        
        pair<bool, int> left = isBalancedfast(root->left, currentlevel+1, leaflevel);
        pair<bool, int> right = isBalancedfast(root->right,currentlevel+1, leaflevel);
        
        bool isbalanced = left.first && right.first;
        int h = max(left.second, right.second) + 1;     //// height of the tree
        pair<bool,int> ans = {isbalanced, h};
        return ans;
    }
  public:
    bool check(Node *root)
    {
        int leaflevel = -1;
        return isBalancedfast(root, 0 , leaflevel).first;
    }
};
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}

// } Driver Code Ends