#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newhead = new ListNode();
        newhead -> next = head;

        ListNode* prev = newhead;
        ListNode* curr = head;

        while(curr){
            while(curr && curr->next && curr->val == curr->next->val){
                curr = curr->next;
            }
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }

        return newhead->next;
    }
};