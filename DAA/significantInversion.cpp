#include <bits/stdc++.h>
using namespace std;

// significant inversion problem: Finding the number of instances such that
// i<j and arr[i] > 2*arr[j]
int significantInversion(std::vector<int>&arr){
    int cnt=0;
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] > 2*arr[j]) cnt++;
        }
    }
    return cnt;
}

// Here we'll use more optimized method using Binary Search Tree
class Node{
    public:
        int subtree;
        int key;
        Node* right;
        Node* left;
        Node():key(-1), subtree(0), right(NULL), left(NULL){}
        Node(int k):key(k), subtree(1), right(NULL), left(NULL){}

};

Node* add(Node* root, int k){
    if(root==nullptr){
        Node* curr = new Node(k);
        return curr;
    }
    if(root->key > k){
        root->left = add(root->left, k);
        root->subtree++;
    }else{
        root->right = add(root->right, k);
        root->subtree++;
    }
    return root;
}
int countpairs(Node* root, int x){
    if(root==nullptr) return 0;
    int cnt=0;
    if(root->key > x){
        if(root->right){
            cnt += (root->right)->subtree;
        }
        cnt+=1;
        cnt+= countpairs(root->left, x);
    }else{
        cnt += countpairs(root->right, x);
    }
    return cnt;
}
int significantInverTree(std::vector<int>&arr){
    int no_of_pairs = 0;
    Node* root = NULL;
    for(int i=0; i<arr.size(); i++){
        
        no_of_pairs += countpairs(root, 2*arr[i]);

        root = add(root, arr[i]);
    }
    return no_of_pairs;
}