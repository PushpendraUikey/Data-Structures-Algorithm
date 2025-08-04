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


// Another efficient implementation using two stacks.
vector<int> spiralOrderTraversal(Node*root){
	stack<Node*> s1, s2;
	s1.push(root);

	vector<int> ans;

	while(!s1.empty() || !s2.empty()){

		while(!s1.empty()){
			Node* top = s1.top(); 
			s1.pop();
			ans.push_back(top->data);
			// Left should be processed first when we go left to right
			if(top->right) s2.push(top->right);
			if(top->left) s2.push(top->left);
		}
		while(!s2.empty()){
			Node* top = s2.top();
			s2.pop();
			ans.push_back(top->data);
			// Right should be processed first when we go right to left
			if(top->left) s1.push(top->left);
			if(top->right) s1.push(top->right);
		}
	}

	return ans;
}