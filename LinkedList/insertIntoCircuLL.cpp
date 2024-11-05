#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to insert a data into a sorted circular linked list 
*/

struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};


// This function should return head of
// the modified list
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* curr = head;
        Node* prev = head;
        bool inserted = false;
        Node* t = new Node(data);
        
        if(curr->data > data){      // insert it into the begining
            while(curr->next!=head){
                curr= curr->next;
            }
            
            t->next = curr->next;
            curr->next = t;
            return t;
        }
        
        while(curr->next != head){
            if(data > curr->data){
                prev = curr;
                curr = curr->next;
            }else{
                //// inserted
                inserted = true;
                t->next = prev->next;
                prev->next = t;
                
                return head;
            }
        }
        if(!inserted){          // it's not needed but no problem(this if condn)
            if(data > curr->data) prev = prev->next;    // data inserted is biggest of all
            
            inserted = true;
            t->next = prev->next;
            prev->next = t;
                
            return head; 
        }
        return head;
    }
};