#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to sort k-sorted doubly linked list, so the DLL is sorted in chunks of k-nodes
whenever k-sorted it looks then idea is to use priority_queue(or heap)
*/

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        DLLNode* curr = head;
        DLLNode* prev = head;
        
        while(curr){
            pq.push(curr->data);
            if(pq.size()==k+1){
                prev->data = pq.top();
                prev = prev->next;
                pq.pop();
            }
            curr = curr->next;
        }
        
        while(!pq.empty()){
            prev->data = pq.top();
            prev = prev->next;
            pq.pop();
        }
        
        return head;
    }
};