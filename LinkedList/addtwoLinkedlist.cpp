#include<bits/stdc++.h>
using namespace std;

/* Algorithm to add two linked lists */


// number in linked list are in the order of highest precision to least, from left to right.

  template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };


Node<int>* add(Node<int>* first, Node<int>* second){

    Node<int>* t1 = first;
    Node<int>* t2 = second;
    Node<int>* prev = NULL;
    int rem = 0;

    while(t1 != NULL && t2 != NULL){
        int val = t1->data + t2->data + rem;
        t1 -> data = val%10;
        rem = val/10;
        prev = t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    while(t1 != NULL){
        int val = t1->data + rem;
        t1 -> data = val %10;
        rem = val/10;
        prev = t1;
        t1 = t1 -> next;
    }
    while(t2 != NULL){
        int val = t2->data + rem;
        Node<int>* temp = new Node<int>(val%10);
        prev -> next = temp;
        prev = temp;
        t2 = t2 -> next;
        rem = val/10;
    }
    while(rem){
        Node<int>* temp = new Node<int>(rem%10);
        prev -> next = temp;
        prev = temp;
        rem /= 10;
    }
    return first;
}
Node<int>* reverse(Node<int>* head){
    Node<int>* prev = NULL;
    Node<int>* fd = NULL;
    while(head != NULL){
        fd = head->next;
        head -> next = prev;
        prev = head;
        head = fd;
    }
    return prev;
}
Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    

    first = reverse(first);
    second = reverse(second);

    Node<int>* sum = add(first, second);

    sum = reverse(sum);

    return sum;
}




// numbers in the linked list is least precsion to higest precision from left to right
class Node1 {
 public:
       int data;
       Node1 *next;
       Node1() {
           this->data = 0;
          this->next = NULL;
      }
       Node1(int data) {
           this->data = data;
          this->next = NULL;
       }
      Node1 (int data, Node1 *next) {
          this->data = data;
          this->next = next;
      }
  };
 

Node1 *addTwoNumbers(Node1 *num1, Node1 *num2)
{
    int rem = 0;
    Node1* t1 = num1;
    Node1* t2 = num2;
    Node1* prev = NULL;

    while(t1 != NULL && t2 != NULL){
        int val = t1->data + t2->data + rem;
        t1 -> data = val%10;
        rem = val/10;
        prev = t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    while(t1 != NULL){
        int val = t1->data + rem;
        t1 -> data = val %10;
        rem = val/10;
        prev = t1;
        t1 = t1 -> next;
    }
    while(t2 != NULL){
        int val = t2->data + rem;
        Node1* temp = new Node1(val%10);
        prev -> next = temp;
        prev = temp;
        t2 = t2 -> next;
        rem = val/10;
    }
    while(rem){
        Node1* temp = new Node1(rem%10);
        prev -> next = temp;
        prev = temp;
        rem /= 10;
    }
    return num1;
}