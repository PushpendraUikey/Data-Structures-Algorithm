#include<bits/stdc++.h>
using namespace std;

/*
Recursive algorithms to remove the middle element of a stack.
*/

void solve(stack<int> &inputStack, int count, int size){
    if(count == size){
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive call;
    solve(inputStack, count+1, size);
    inputStack.push(num);
}
void DeleteMidstack(stack<int> &inputStack){
    int size = inputStack.size();
    solve(inputStack, 0, size/2);
}