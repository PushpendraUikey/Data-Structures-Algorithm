#include<bits/stdc++.h>
using namespace std;

// stack implementation using array

class  Stack
{
private:
    /* data */
public:
    int *arr;
    int top;
    int size;
     Stack(int);
    ~ Stack();
    void push(int );
    void pop();
    int peek();
    bool isEmpty();
};

 Stack
:: Stack
(int size=0):
size(size), 
top(-1)
{
    arr = new int[size];
}
 Stack::~ Stack()
{
}
void Stack::push(int e){
    if(size-top > 1){
        top++;
        arr[top] = e;
    }else{
        cout << "Stack Overflow" << endl;
    }
}
void Stack::pop(){
    if(top >=0 ){
        top--;
    }else{
        cout << "Stack Underflow" << endl;
    }
}
int Stack::peek(){
    if(top>=0){
        return arr[top];
    }else{
        cout << "Stack is empty" << endl;
        return -1;
    }
}
bool Stack::isEmpty(){
    if(top==-1) return true;
    else return false;
}
//////// Last in First out principal it follows.
int main(){
    // create stack
    stack<int> st;

    // Push
    st.push(2);
    st.push(4);

    // pop
    st.pop();

    cout << st.top() << endl;
    cout << st.empty() << endl;


    //////////////// Implementation of stack
    Stack stk(9);
    stk.push(2);
    cout << stk.peek() << endl;
    
    stk.push(45);
    stk.push(23);
    cout << stk.isEmpty() << endl;
    stk.pop();
    stk.pop();
    stk.pop();
    cout << stk.isEmpty() << endl;
    cout << stk.peek() << endl;
}