#include<bits/stdc++.h>
using namespace std;


/// @brief  alrogithm to find the path to any value x from root 
/// @tparam T 

template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};

void solve(TreeNode<int>* root, int x, vector<int>& v, bool& found){
	if(root==nullptr){
		return;
	}
	
	if(!found){
		v.push_back(root->data);
		if(root->data == x) found = true;
	}
	solve(root->left,x , v, found);
	solve(root->right, x,  v, found);
	if(!found){		//// if path is not found then backTrack
		v.pop_back();
	}
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	bool found = false;
	solve(root, x, ans, found);

	return ans;
}