#include<bits/stdc++.h>
using namespace std;

//// tickets are sold in a very wierd way, first sold to front-K people and the lask-K people, 
//// we have to find out which one will be the last to receive the ticket

int distributeTicket(int N, int K) {

    deque<int> dq;
    for(int i=1; i<= N; i++){
        dq.push_back(i);
    }

    bool front = true;

    while(dq.size()>K){
        int c = K;
        if(front){
            while(c-->0) dq.pop_front();
            front = false;
        }else{
            while(c-->0) dq.pop_back();
            front = true;
        }
    }

    if(front) return dq.back();
    else return dq.front();
}