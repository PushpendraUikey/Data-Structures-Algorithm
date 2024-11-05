#include<bits/stdc++.h>
using namespace std;

/* Algorithm to sort the linked list based on 0, 1 and 2 as these are the only values the LL has.*/

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

// Approach 1

void insertAttail(Node* &head, Node* &curr){
    head -> next = curr;
    head = curr;
}
Node* sortList(Node *head){
    // Write your code here.
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;
    while(curr != NULL){
        int value = curr -> data;

        if(value == 0){
            insertAttail(zerotail, curr);
        }
        if(value == 1){
            insertAttail(onetail, curr);
        }
        if(value == 2){
            insertAttail(twotail, curr);
        }
        curr = curr -> next;
    }
    if(onehead-> next != NULL)
    zerotail -> next = onehead -> next;
    else{
      zerotail -> next = twohead -> next;  
    }
    onetail -> next = twohead -> next;
    twotail -> next = nullptr;

    head = zerohead -> next;
    delete onehead;
    delete twohead;
    delete zerohead;
    return head;
}


// Approach 2
Node* sortList1(Node *head){
    if(head == NULL) return head;
    int numzero = 0;
    int numone = 0;
    int numtwo = 0;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0) numzero++;
        else if(temp->data == 1) numone++;
        else numtwo++;
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(numzero){
            temp->data = 0;
            numzero--;
        }else if(numone){
            temp->data = 1;
            numone--;
        }else{
            temp -> data = 2;
            numtwo--;
        }
        temp = temp->next;
    }
    return head;
}