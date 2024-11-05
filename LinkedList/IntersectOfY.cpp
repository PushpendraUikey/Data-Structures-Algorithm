#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; 

// haha, I didn't know it is the case.
// Biggest learning, you can compare the pointers, if they are referring to the same address then they are equal 

class Solution {
    void countNode(Node* head, int& v){
        while(head){
            v++;
            head = head->next;
        }
    }
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        
        int s1 = 0;
        int s2 = 0;
        
        countNode(head1, s1);
        countNode(head2, s2);
        
        //// make the both pointer pointing at same length;
        if(s1 > s2){
            while(s1 != s2){
                head1 = head1->next;
                s1--;
            }
        }else{
            while(s1 != s2){
                head2 = head2->next;
                s2--;
            }
        }
        
        int ans = -1;
        
        /* When both pointers are at the same length distant start moving towards each other,
            when you encounter the first data match, then that is intersection point*/
        while(head1 && head2){
            if(head1 == head2){
                ans = head1->data;
                break;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return ans;
    }
};