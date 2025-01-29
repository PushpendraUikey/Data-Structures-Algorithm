#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data, size;
    Node *left, *right;
    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};


// This technique is brute force and it has TC of O(n) for each rank search as it traverse entire tree.
int findRank(Node* root, int x){
    if(!root){
        return 0;
    }
    int rank_left = findRank(root->left, x);
    int rank_right = findRank(root->right, x);

    if(root->data <= x){
        return 1 + rank_left + rank_right;
    }else{
        return rank_left + rank_right;
    }
}

// Now we'll take the benefit of tree being ordered.
// Here we reduced the recursive calls. But worst case scenario is that it'll traverse entire tree.
// making it O(n) algorithm.
int findRank1(Node* root, int x){
    if(!root) return 0;
    if(root->data <= x){
        return 1 + findRank1(root->left, x) + findRank1(root->right, x);
    }else{
        return findRank1(root->left, x);
    }
}


// Here it can be more optimize if we can skip the traversal of left subtree by storing the
// meta data about the size of each subtree [augmenting each node]
int findRank2(Node* root, int x){
    if(!root) return 0;
    if(root->data <= x){
        if(!root->left){
            return 1 + findRank2(root->right, x);
        }else{
            return 1 + root->left->size + findRank2(root->right, x);
        }
    }else{
        return findRank2(root->left, x);
    }
}

// Here's the tail recursion method to calculate the rank
int findRank3(Node* root, int x, int&current){
    if(!root){
        return current;
    }
    if(root->data <= x){
        if(!root->left) current++;
        else current = 1 + current + root->left->size;
        return current;
    }else{
        return findRank3(root->left, x, current);
    }
}
// Tail-recursive functions can be tail-call optimized, which means that a single frame 
// on the call stack can be reused for each call. 
// Without tail-call optimization, we risk the stack overflow error if the path being
//  visited is too deep.