#include <bits/stdc++.h>
#include "allnodeDef.h"
using namespace std;

/*
Here is the algorithm for zig-zag traversal of Binary Tree
Traversal is done level wise.
with lowest level first
Implementaion is similar to BFS
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	if(root == NULL) {
    	    return ans;
    	}
    	queue<Node*> q;
    	
    	q.push(root);
    	bool leftoright = true;
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    
    	    vector<int> result(size);
    	    for(int i=0; i<size; i++){
    	        Node* frontNode = q.front();
    	        q.pop();
    	        
    	        int index = leftoright ? i : size -i -1;
    	        result[index] = frontNode->data;
    	        
    	        if(frontNode->left){
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right){
    	            q.push(frontNode->right);
    	        }
    	    }
    	    for(auto i:result){
    	        ans.push_back(i);
    	    }
    	    leftoright = leftoright ? false : true;
    	}
    	return ans;
    }
};