#include<bits/stdc++.h>
using namespace std;

/*
Implementing the queue using single stack.
There is better implementation using two stacks
*/

class Queue {
    // Define the data members(if any) here.
    void insertatBottom(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int val = myStack.top();
    myStack.pop();

    insertatBottom(myStack, x);

    myStack.push(val);
    }

    void reverse(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    reverse(stack);

    insertatBottom(stack,num);
    }
    bool reversed;
    stack<int> st;
    
    public:
    Queue() {
        reversed = false;
    }

    void enQueue(int val) {
        if(reversed){
            reverse(st);
            reversed = false;
        }
        st.push(val);
        
    }

    int deQueue() {
        if(st.empty()) return -1;

        if(!reversed){
            reverse(st);
            reversed = true;
        }
        int v = st.top();
            st.pop();
            return v;
    }

    int peek() {
        if(st.empty()) return -1;

        if(!reversed){
            reverse(st);
            reversed = true;
        }
        return st.top();
    }

    bool isEmpty() {
        return st.empty();
    }
};