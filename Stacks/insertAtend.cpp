#include <bits/stdc++.h> 
using namespace std;

/*
Algorithm to push an element at bottom of stack.
*/

void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int val = myStack.top();
    myStack.pop();

    solve(myStack, x);

    myStack.push(val);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;    
}