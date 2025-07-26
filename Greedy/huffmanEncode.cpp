#include<bits/stdc++.h>
using namespace std;

/// @brief  Given frequencies in sorted orders of string's char's this is the huffman code to generate 
// B tree for encoding, 
class Tree {
    public:
    int f;
    Tree* left;
    Tree* right;
    Tree(int d):f(d),left(nullptr),right(nullptr){}
};
class compare{
    public:
    bool operator()(Tree*a, Tree*b){
        return a->f > b->f;
    }
};
class Solution
{
    void solve(Tree* root, vector<string>& ans, string& path){
        if(root==nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
           
            if(!path.empty()) ans.push_back(path);
            return;
        }
        path.push_back('0');
        if(root->left) solve(root->left, ans, path);
        path.pop_back();
        path.push_back('1');
        if(root->right) solve(root->right, ans, path);
        path.pop_back();
    }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    vector<string> ans;
		    string encode="";
		    
		    Tree* root = new Tree(-1);
		    priority_queue<Tree*, vector<Tree*>, compare> pq;
		    for(auto &i:f){
		        pq.push(new Tree(i));
		    }
		    
		    while(pq.size() > 1){
		        Tree* a = pq.top();
		        pq.pop();
		        Tree* b = pq.top();
		        pq.pop();
		        
		        Tree* parent = new Tree(a->f+b->f);
		        parent -> left = a;
		        parent -> right = b;
		        pq.push(parent);
		    }
		    
		    root = pq.top();
		    
		    solve(root, ans, encode);
		    
		    return ans;
		}
};