#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to merge K-sorted lists.
*/

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<int, vector<int>, greater<int>> pq;

    int size = listArray.size();

    for(int i=0; i< size; i++){
        Node* temp = listArray[i];
        while(temp){
            pq.push(temp->data);
            temp = temp -> next;
        }
    }

    Node* temp = new Node(-1);
    Node* curr = temp;

    while(!pq.empty()){
        Node* t = new Node(pq.top());
        temp -> next = t;
        temp = t;
        pq.pop();
    }

    return curr->next;
}

////// Alternative Solution

class compare{
    public:
    bool operator()(Node*a, Node* b){           //// You have to overload the operator in your own.
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*>, compare> pq;

    int k = listArray.size();

    if(k==0) return nullptr;

    for(int i=0; i<k; i++){
        if(listArray[i] != NULL){
            pq.push(listArray[i]);
        }
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    while(pq.size() > 0){
        Node* temp = pq.top();
        pq.pop();

        if(temp -> next ){
            pq.push(temp->next);
        }
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail -> next = temp;
            tail = temp;
        }
    }
    return head;
}