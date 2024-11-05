#include<bits/stdc++.h>
using namespace std;

/// @brief Given solution is to the problem to clone the linked list which has random pointer and next pointer
/// random pointer pointing to some random linked list 

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *copyList(Node *head) {
        // Write your code here
        Node* newNode;
        Node* temp = nullptr;
        Node* t = nullptr;
        Node* curr = head;
        
        while(curr){
            if(!temp){
                temp = new Node(curr->data);
                newNode = temp;
                t = temp;
                curr = curr -> next;
            }else{
                temp = new Node(curr->data);
                t->next = temp;
                t = temp;
                curr = curr -> next;
            }
        }
        
        curr = head;
        temp = newNode;
        
        while(curr){
            Node* r = curr->random;
            if(r){
                Node* tr = new Node(r->data);
                temp -> random = tr;
            }
            curr = curr->next;
            temp = temp ->next;
        }
        
        return newNode;
        
    }
};