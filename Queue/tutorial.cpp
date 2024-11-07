#include<bits/stdc++.h>
using namespace std;

/* Implementation and algorithms on queues: Circular implementation is important */

// Queue implementation
class Queue {
public:
    int *arr;
    int size;
    int front1;
    int rear;

    Queue() {
        size = 1000000;
        arr = new int[size+1];  // one space we leave for full
        front1 = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(rear == front1) return true;
        else return false;
    }

    void enqueue(int data) {
        if(rear >= size){       // not complete because we still can have enough space left in the beginning, i.e. need of cicular implementation
            cout << "Queue is full" << endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(front1 == rear){
            return -1;
        }else{
            int val = arr[front1];
            arr[front1] = -1;
            front1++;
            if(front1 == rear){ // initialize from beginning
                front1 = 0;
                rear = 0;
            }
            return val;
        }
    }

    int front() {
        if(front1 == rear){
            return -1;
        }else{
            return arr[front1];
        }
    }
};

//////// circular implementation
class CircularQueue{
    public:
    int * arr;
    int size;
    int rear;
    int front;
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){    // We are keeping the rear at the element we just pushed and not at the one step ahead
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        }else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){  // single element is present
            front = rear = -1;
        }else if(front == size -1){
            front = 0; // cyclic nature
        }else{
            front++;
        }
        return ans;
    }
};

// Doubly ended queue implementation;

class Deque
{
    int* arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()){
            return false;
        }else if(isEmpty()){
            front = rear = 0;
        }else if(rear == size-1 && front != 0){
            rear = 0;
        }else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){  // single element is present
            front = rear = -1;
        }else if(front == size -1){
            front = 0; // cyclic nature
        }else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()){// front or rear both will be -1 at the same time
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear){  // single element is present
            front = rear = -1;
        }else if(rear == 0){
            rear = size - 1; // cyclic nature
        }else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()) return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()) return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1) return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rear == size-1) || ( front != 0 && rear == (front-1)%(size-1))){
            return true;
        }else {
            return false;
        }
    }
};

int main(){
    // queue<int> q;
    // for(int i=0; i<10; i++) q.push(i);
    // for(int i=0; i<10; i++){
    //     cout << q.front() << endl;
    //     cout << q.back() << endl;
    //     cout << q.empty() << endl;
    //     cout << "________________________________________" << endl;
    //     q.pop();
    // }
    // cout << q.empty() << endl;

    deque<int> d;
    d.push_back(13);
    d.push_front(24);
    d.push_back(15);
    cout << d.front() << endl;
    cout << d.back() << endl;
}