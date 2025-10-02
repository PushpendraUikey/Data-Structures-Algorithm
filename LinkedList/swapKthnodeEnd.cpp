#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a singly linked list and an integer k. Swap the kth node (1-based index) 
from the beginning and the kth node from the end of the linked list. Return the head of 
the final formed list and if it's not possible to swap the nodes return the original list
*/

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        Node* curr = head;
        int len = 0;
        while(curr) {
            curr = curr->next;
            len++;
        }
        if( k>len) return head;
        int lenminusk = len - k;
        Node* other = head;
        while(lenminusk > 0){
            other = other->next;
            lenminusk--;
        }
        curr = head;
        while(k>1){
            curr = curr->next;
            k--;
        }
        
        swap(curr->data, other->data);
        return head;
    }
};