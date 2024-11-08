#include<bits/stdc++.h>
using namespace std;

/*
Following algorithm recursively reverses the stack
O(n^2) complexity it has.
*/

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

void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertatBottom(stack,num);
}