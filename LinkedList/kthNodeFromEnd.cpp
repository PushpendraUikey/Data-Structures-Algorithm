#include<bits/stdc++.h>
using namespace std;

/* 
Algorithm to detect kth node from the end in linked list
*/

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
    Node* reverse(Node* head){
        if(head == nullptr) return nullptr ;
        Node* curr = head;
        Node* prev = NULL;
        Node* t =NULL;
        
        while(curr){
            t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }
  public:
    int getKthFromLast(Node *head, int k) {
        Node* curr = reverse(head);
        while(k-->0 && curr){
            
            if(k==0) return curr->data;
            curr = curr -> next;
        }
        return -1;
    }
};