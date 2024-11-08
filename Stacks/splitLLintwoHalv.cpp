#include<bits/stdc++.h>
using namespace std;

/*
Algorithm splits the Circular linked list into two halves*/

struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};


//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    void splitList(struct Node *head, struct Node **head1_ref,
                   struct Node **head2_ref) {
        if(head == NULL || head -> next == head){
            *head1_ref = head;
            *head2_ref = head;
            return ;
        }
        Node* fast = head;
        Node* slow = head;
        
        while(fast->next != head){
            fast = fast -> next;
            if(fast->next != head){
                fast = fast -> next;
                slow = slow->next;
            }
        }
        Node* head2 = slow->next;
        // head 1
        slow -> next = head;
        *head1_ref = head;
        // second;
        fast -> next = head2;
        *head2_ref = head2;
    }
};