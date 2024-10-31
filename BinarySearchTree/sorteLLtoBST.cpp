#include<bits/stdc++.h>
using namespace std;

struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; 

class Solution {
    int countNode(LNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head = head -> next;
        }
        return cnt;
    }
    // we are basically start building the tree from left-most partand keep building it till we reach root(mid)
    // then we go to right subpart and again start building it till we're done.
    TNode* solve(LNode *& head, int n){
        if(n<=0 || head == nullptr) return nullptr;
        
        TNode* left = solve(head, n/2); /// construct a left subtree.
        
        TNode* root = new TNode(head->data);
        root -> left = left;
        
        head = head -> next;
        
        root -> right = solve(head, n - n/2 - 1);   /// construct a right subtree
    
        return root;
    }
  public:
    TNode *sortedListToBST(LNode *head) {
        // code here
        return solve(head, countNode(head));
    }
};