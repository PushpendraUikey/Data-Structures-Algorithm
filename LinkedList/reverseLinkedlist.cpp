#include<bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.
struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
/* normal loop way to reverse the linked list */
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fd = NULL;
        

        while(curr != NULL){
            fd = curr->next;    // to track prev
            curr->next = prev;      // to track forward
            prev = curr;
            curr = fd;
        }
        return prev;
    }
};

/* One of the recursive way to reverse the linked list */
class Solution2 {
private: 
    ListNode* solve(ListNode* fd, ListNode* curr, ListNode* prev){
        if(curr==NULL) return prev;
        fd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fd;
        return solve(fd, curr, prev);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* fd = NULL;
        ListNode* curr = head;
        return solve(fd, curr, prev);
    }
};

/* Recursive approach to reverse the linked list */
class Solution3 {
private: 
    void solve(ListNode* &head, ListNode* curr, ListNode* prev){
        if(curr==NULL) {
            head = prev;
            return;
        }
        solve(head, curr->next, curr);
        curr->next = prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        solve(head, curr, prev);
        return head;
    }
};