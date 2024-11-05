#include<bits/stdc++.h>
using namespace std;

/* Algorithm to check if the linked list represents a palindrome */

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

/////////////////////////////////// Solution 1


/// // To find middle we usually use fast-slow approach

LinkedListNode<int>* getMiddle(LinkedListNode<int> *head){
    LinkedListNode<int>* fast = head;
    LinkedListNode<int>* slow = head;
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        
        slow = slow->next;
    }
    return slow;
}

LinkedListNode<int>* reverse(LinkedListNode<int>* head){
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* fd = head;
    while(curr != NULL){
        fd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fd;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL) return true;

    LinkedListNode<int>* middle = getMiddle(head);
    LinkedListNode<int>* mid = reverse(middle);
    while(mid!=NULL){
        if(head->data != mid->data) return false;
        head = head -> next;
        mid = mid->next;
    }
    return true;
}

////////////////////////////// Solution 2

bool isPalindrome1(LinkedListNode<int> *head) {
    vector<int> ans;
    int n = 0;
    LinkedListNode<int> *temp = head;
    while(temp != NULL){
        ans.push_back(temp->data);
        n++;
        temp = temp -> next;
    }
    int s = 0; int e = n-1;
    while(s<e){
        if(ans[s++] != ans[e--]){
            return false;
        }
    }
    return true;
}