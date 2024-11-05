#include<bits/stdc++.h>
using namespace std;

/*
Algorithm for Merge Sort over linked-list
Not writen by me
*/

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

node *findMid(node *head) {
    node *slow = head;
    node *fast = head->next;
    while (fast != nullptr && fast -> next != nullptr){
        fast = (fast -> next) -> next;
        slow = slow -> next;
    }
    return slow;
}
node* merge(node* left, node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;

    node* ans = new node(-1);
    node* temp = ans;

    // merge two sorted 
    while(left != NULL && right != NULL){
        if(left -> data < right->data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while( left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    while( right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
}
node* mergeSort(node *head) {
    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }

    node* mid = findMid(head);

    node* left = head;
    node* right = mid->next;
    mid -> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    // merging both sides
    node* result = merge(left,right);

    return result;
}