#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to remove loop from linked list
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

/* This technique of floyd is based on slow and fast pointer where slow moves one step and fast moves 
    two steps in each interval(they are moving interval by interval). The two pointers will intersect 
    while they are on the loop.*/
Node* floydDetectionLoop(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    // while(slow != NULL && fast  != NULL){
    //     fast = fast -> next;
    //     if(fast != nullptr){
    //         fast = fast->next;
    //     }
    //     slow = slow -> next;
    //     if(slow == fast) return slow;
    // }
    while(fast  != NULL && fast -> next != NULL){   //// Above algorithm doesn't cover all the edge cases.
        fast = (fast -> next)->next;
        slow = slow -> next;
        if(slow == fast) return slow;
    }
    return NULL;
}

/* This will return the node at which the node in the end points to form the loop */
Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydDetectionLoop(head);
    if(intersection == NULL) return NULL;
    Node* slow = head;

    while(slow!= intersection){
        slow = slow->next;
        intersection = intersection ->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    if(head == NULL) return head;
    Node* startOfloop = getStartingNode(head);
    Node* temp = startOfloop;
    if(startOfloop==NULL) return head;  /* if it already does not have loop */
    while(temp -> next != startOfloop){ /* We're finding the last node of LL which is causing the loop */
        temp = temp -> next;
    }
    temp->next = NULL;
    return head;
}