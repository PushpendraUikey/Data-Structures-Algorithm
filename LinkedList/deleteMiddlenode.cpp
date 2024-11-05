#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to delete the middle node of a linked list
*/

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* deleteMiddle(Node* head){
    if(head == NULL ){
        return head;
    }
    // one element
    if(head -> next == NULL){
        delete head;
        head = NULL;
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != nullptr){
            fast = fast -> next;
        }
        if(fast == nullptr) break;
        slow = slow->next;
    }
    Node* t = slow->next;
    if(t->next != nullptr){
        slow->next = t->next;
    }else{
        slow -> next = nullptr;
    }
    delete t;
    t = nullptr;
    return head;
}