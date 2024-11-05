#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to delete duplicate nodes from linked list
*/

class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

// Sorted Linked List
// function deletes the Node which contains duplicate element

Node* uniqueSortedList(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && curr -> data == (curr->next)->data){
            Node* nt = (curr->next)->next;

            delete curr->next;

            curr->next = nt;

        }else{
            curr = curr->next;
        }
    }
    return head;
}

// Unsorted Linked List
// Delete nodes contain duplicates using loops

Node* uniqueListloop(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    while(temp != nullptr){
       int val = temp -> data;
       Node* t = temp->next;
       Node* prv = temp;
       while(t != nullptr){
        if(t->data == val){
            prv->next = t->next;
            delete t;
            t = prv -> next;
        }else{
            prv = t;
            t = t->next;
        }
        
       } 
       temp = temp->next;
    }
    return head;
}

// Deletes nodes in unsorted list using extraspace.

Node* uniqueListspace(Node* head){
    if(head == NULL) return head;

    unordered_set<int> st;
    Node* prev = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        int val = curr->data;
        if(st.find(val) != st.end()){
            prev->next = curr->next;
            delete curr;
            curr = prev -> next;
        }else{
            st.insert(val);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}