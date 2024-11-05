#include<bits/stdc++.h>
using namespace std;

/* Algorithm to add 1 to the number represeted by linked list */

  class Node {
  public:
       int data;
       Node *next;
       Node() {
           this->data = 0;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->next = NULL;
       }
       Node (int data, Node *next) {
           this->data = data;
           this->next = next;
       }
  };

Node* reverse(Node* head){
    if(head == NULL) return head;
    Node* curr = head;
    Node* fd = head;
    Node* prev = NULL;
    while(curr != NULL){
        fd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fd;
    }
    return prev;
}
Node* addOne(Node* head) {
    // Write your code here
    head = reverse(head);

    Node* t = head;
    Node* fd = head;
    int v = t -> data + 1;
    int rem = 0;
    t->data = v%10;
    rem = v/10;
    t = t->next;
    while(t != NULL){
        v = t->data + rem;
        t->data = v%10;
        rem = v/10;
        fd = t;
        t = t->next;
    }
    while(rem){
        Node* temp = new Node(rem%10, NULL);
        fd->next = temp;
        rem = rem/10;
    }
    head = reverse(head);
    return head;
}