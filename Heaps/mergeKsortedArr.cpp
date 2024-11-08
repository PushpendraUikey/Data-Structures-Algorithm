#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to merge K-sorted lists
*/
/// @brief  This question is very important and tricky question,
/// uses some kind of brief information storage to solve


class node{
    public:
    int data;
    int i;
    int j;

    node(int d, int a, int b): data(d), i(a), j(b) {}

};

class compare{
    public:
    bool operator()(node*a, node*b){
        return a->data > b->data;
    }
};

vector<int> mergeKsortedArr(vector<vector<int>>& kArrays, int k){
    priority_queue<node*, vector<node*>, compare> pq;   // min-heap, it is.

    for(int i=0; i<k; i++){
        node* tmp = new node(kArrays[i][0], i, 0);
        pq.push(tmp);
    }

    vector<int> ans;

    while(pq.size() > 0){
        node* tmp = pq.top();

        ans.push_back(tmp -> data);
        pq.pop();

        int i = tmp -> i;
        int j = tmp -> j;

        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            pq.push(next);
        }
    }
    return ans;
}