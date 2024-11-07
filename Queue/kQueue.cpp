#include<bits/stdc++.h>
using namespace std;

/*
Implementing k-queues in a signle array.
*/

class kQueue{
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    public:
        kQueue(int n, int k):n(n), k(k){
            front = new int[k];
            rear = new int[k];
            next = new int[n];
            arr = new int[n];
            for(int i=0; i< k; i++){
                front[i] = rear[i] = -1;
            }
            for(int j=0; j<n; j++){
                next[j] = j+1;
            }
            next[n-1] = -1;
            freespot = 0;
        }    
        void enqueue(int data, int qn){
            /// overflow
            if(freespot == -1){
                cout << "No empty space is available!" << endl;
                return;
            }
            // find first free index
            int index = freespot;
            //update freespot
            freespot = next[index];

            // check whether first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }else{
                // link new element to the prev element
                next[rear[qn-1]] = index;
            }

            /// Update next
            next[index] = -1;   // next of index is occupied

            /// update rear
            rear[qn-1] = index; // now the rear points to index

            /// Push element
            arr[index] = data;
        }
        int pop(int qn){

            if(front[qn-1] == -1){
                cout << "queue is underflow!" << endl;
                return -1;
            }

            // find index to pop
            int index = front[qn-1];

            // push the front ahead;
            front[qn-1] = next[index];

            /// manage the freeslot
            next[index] = freespot;
            freespot = index;           //index free ho gya 

            return arr[index];
        }
};