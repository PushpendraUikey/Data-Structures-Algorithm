#include<bits/stdc++.h>
using namespace std;

/*
Solution to a famous Binary Tree problem where we've to burn 
a tree from a given node and the neighbouring connected nodes burn in one go.
RETURN: How much time it'd take to burn the entire tree
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

class Solution {
  public:
    Node* createParentMapping(Node* root, int t, map<Node*, Node*>& nodeToParent){
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->data == t){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
        
    }
    void burnTree(Node* root, map<Node*, Node*> &nodeToParent, int &ans){
        map<Node*, bool> visited;   //// Important to keep track of burnt nodes.
        queue<Node*> q;
        q.push(root);
        visited[root] = true;
        
        while(!q.empty()){
            bool flag = 0;
            
            int size = q.size();
            for(int i=0; i<size; i++){
                ////// Process the neighbouring nodes(left, right, and parent)
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if(flag == 1) ans++;
        }
    }
    int minTime(Node* root, int target) 
    {
        int ans = 0;
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        burnTree(targetNode, nodeToParent, ans);
        
        return ans;
        
    }
};