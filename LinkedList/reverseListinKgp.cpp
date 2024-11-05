#include<bits/stdc++.h>

using namespace std;
/*
Your task is to reverse the order of each group of 'k' consecutive nodes,
 if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.
*/
 
  class Node {
  public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
 };

bool issafe(Node* head, int k){
    int cnt = 0;
    while(head != NULL && cnt < k){
        head = head -> next;
        cnt++;
    }
    if(cnt >= k) return 1;
    else return 0;
}

/* Recursive approach to reverse the linked list in groups of k-nodes */

Node* kReverse(Node* head, int k) {
    if(head == NULL) return head;
    if(!issafe(head, k)){   /* not enough elements in the linked list */
        return head;
    }
    Node* fd = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int cnt = 0;
    while(curr != NULL && cnt < k){
        fd = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = fd; 
        cnt++;
    }
    if (fd != NULL) {
        head -> next = kReverse(fd, k);
    }
    
    return prev;
}

int main(){
    int n; cin >> n;
    int x; cin >> x;
    Node* head = new Node(x);
    Node* tail = head;
    for(int i{0}; i<n-1; i++){
        cin >> x;
        Node* temp = new Node(x);
        tail->next = temp;
        tail = temp;
    }
    int k; cin >> k;
    head = kReverse(head, k);
}