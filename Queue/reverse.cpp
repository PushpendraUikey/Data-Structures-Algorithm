#include<bits/stdc++.h>
using namespace std;

/*Algorithm to reverse the queue*/

void reverse(queue<int> &q){
    if(q.empty()) return;
    int n = q.front();
    q.pop();

    reverse(q);
    q.push(n);
}
//////// second approach for this is to use stack, and reverse(Quiet easy);

////// To reverse first k element of queue
void reverse(queue<int> &q,int k)
{
    if(q.empty() || k==0) return;

    queue<int> temp;
    stack<int> st;
    
    while(k-->0){
        st.push(q.front());
        q.pop();
    }
    while(!q.empty()){
        temp.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!temp.empty()){
        q.push(temp.front());
        temp.pop();
    }
}