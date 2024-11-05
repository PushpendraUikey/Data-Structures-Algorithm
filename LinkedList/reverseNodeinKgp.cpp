#include <bits/stdc++.h>

/*
You are given a Singly Linked List of integers and an integer array 'B' of size 'N'. 
Each element in the array 'B' represents a block size. Modify the linked list
by reversing the nodes in each block whose sizes are given by the array 'B'.
 
 If you encounter a situation when 'B[i]' is greater than the number of remaining 
 nodes in the list, then simply reverse the remaining nodes as a block and ignore 
 all the block sizes from 'B[i]'.
 */
using namespace std;

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

Node* reverseNode(Node* head, int i, int n, int b[]){
	if(head == nullptr) return head;
	Node* prev = NULL;
	Node* curr = head;
	Node* fd = NULL;

	/* If index already out of bound then no need to reverse, we are done. */
	if(i >= n){
		return head;
	}

	/* Exhausting all potential possible cases of zero's in Array B as block size of zero means nothing to reverse.*/
	int k = b[i];
	while(k==0){
		i++;
		if(i>=n) return head;
		k=b[i];
	}
	int cnt = 0;

	/* Reversing the linked list */
	while(curr!=NULL && cnt < k){
		fd = curr->next;
		curr->next = prev;
		prev = curr;
		curr = fd;
		cnt++;
	}
	
	if(curr != NULL){
		/* After reversing the head is last node hence return of recurse should be it's next*/
		head->next = reverseNode(curr, i+1, n, b);
	}
	return prev;	// this is the first node after reversing.
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return reverseNode(head, 0, n, b);
}

//// Here's the solution to reverse a linked list in k'th groups!
// this is the loop base solution
/*

class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        // Complete this method
        node* curr = head;
        node* prev = nullptr;
        node* temp = nullptr;
        node* first = nullptr;
        node* fil = nullptr;
        int j=0;
        
        //// first iteration
        first = curr;
        
        while(j++ < k && curr){
                temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
        }
    
        // first -> next = curr;
        head = prev;
        while(curr){
            j=0;
            fil = curr;
            while(j++ < k && curr){
                temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
            }
            first -> next = prev;
            first = fil;
        }
        if(fil) fil -> next = nullptr;
        
        return head;
    }
};

*/