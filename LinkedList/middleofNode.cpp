#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find middle element of linked list
*/

class Node{
    public:
    Node* next;
    int val_;
    Node(int val=0, Node* n = NULL): val_(val), next(n) {}
};
Node* middleOfNode(Node* head){
    // only one node or no node
    if(head == NULL || head -> next == NULL){
        return head;
    }
    // Two nodes - 
    if((head->next) -> next == NULL){
        return head -> next;
    }
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow->next;
    }
    return slow;
}