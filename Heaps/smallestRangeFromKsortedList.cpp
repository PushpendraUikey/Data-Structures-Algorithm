#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find the smallest range in Ksorted list
*/

class Node{
    public:
    int data;
    int i;
    int j;

    Node(int d, int row, int col) : data(d), i(row), j(col) {}
};

class compare{
    public:
    bool operator()(Node*a, Node*b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini=INT_MAX, maxi = INT_MIN;

    priority_queue<Node*, vector<Node*> , compare > pq;

    // processing the first element of all the lists.
    for(int i=0; i<k; i++){
        int e = a[i][0];
        
        mini = min(mini, e);
        maxi = max(maxi, e);
        
        pq.push(new Node(e, i, 0));
    }


    int start = mini, end = maxi;
    while(!pq.empty()){
        Node* temp = pq.top();
        pq.pop();

        mini = temp -> data;

        if(maxi-mini < end-start){  //// if new range is smaller then update the range
            start = mini;
            end = maxi;
        }

        if(temp->j+1 < n){      //// next element exists in the list.
            int e = a[temp->i][temp->j + 1];    // extracting the next ele
            maxi = max(e, maxi);        //// updating the maxi as only this might change.
            pq.push(new Node(e, temp->i, temp->j + 1));
        }else{
            break;  // This condition will reach when we are out of any one list, that means now the 
                    // answer can't be found, because values will out of atleast one list hence range won't
                    // include element from that list.
        }
    }

    return (end-start+1);
}