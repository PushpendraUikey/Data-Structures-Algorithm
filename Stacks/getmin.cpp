#include<bits/stdc++.h>
using namespace std;
/*
Implementing a getminimum function in a stack, using constant space and constant time approach
*/


class SpecialStack {
    public:
    stack<int> s;
    int mini;
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }else{
            if(data < mini){
                s.push(2*data-mini);// We want to access the mini of previous data's
                mini = data;
            }else{
                s.push(data);
            }
        }
    }

    void pop() {
        if(s.empty()) {
            cout << "stack is empty!" << endl;
            return;
        }
        if(s.top()<mini){
            mini = 2*mini - s.top();
            s.pop();
        }else{
            s.pop();
        }
    }

    int top() {
        if(s.empty()){
            cout << "stack is empty!" << endl;
            return -1;
        }
        int t = s.top();
        if(t < mini) return mini;
        else return t;
    }

    int getMin() {
        if(s.empty()){
            cout << "stack is empty!" << endl;
            return -1;
        }
        return mini;
    }  
};


// Second approach using, O(1) time and O(n) space;
// using two stacks
class SpecialStack1 {
    public:
    stack<int> s;
    stack<int> mini;
    int m;
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini.push(data);
            m = data;
        }else{
            s.push(data);
            m = min(data, m);
            mini.push(m);
        }
    }

    void pop() {
        if(s.empty()) {
            cout << "stack is empty!" << endl;
            return;
        }
        s.pop();
        mini.pop();
    }

    int top() {
        if(s.empty()){
            cout << "stack is empty!" << endl;
            return -1;
        }
        return s.top();
    }

    int getMin() {
        if(s.empty()){
            cout << "stack is empty!" << endl;
            return -1;
        }
        return mini.top();
    }  
};