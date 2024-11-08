#include<bits/stdc++.h>
using namespace std;

/// Heap is a Complete Binary Tree, that comes with a heap order property.
/// CBT means every level is completely filled exept the last level
/// Nodes are always added from the left node

/// Here we're doing the array implementation of the heap. 
// indexing used is 1-based

class heap{
    public:
        int arr[100];
        int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){// constructing the max heap, so constantly checking if the ele is greater than parent.
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else return;                // if everything is sorted then we're done.
        }
    }
    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    void deletefromHeap(){              // we are deleting the root node.
        if(size==0) {
            cout << "Nothing to delete." << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i=1;
        while(i < size){
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if(left < size && arr[largest] < arr[left]){
                largest = left;
            }
            if(right < size && arr[largest] < arr[right]){
                largest = right;
            }

            if(i != largest){
                swap(arr[i], arr[largest]);
                i = largest;
            }else{
                break;
            }
        }
    }
};

///  Same logic as we did in deletefromHeap, bcz at the end we have to heapify only.
///  heapify converts the given tree into heap from the given index and below. 
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2* i + 1;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n){ //putting the largest element in the end.
    int size = n;
    while(size > 1){

        swap(arr[size], arr[1]);

        size--;

        heapify(arr, size, 1);

    }
}

int main(){
    heap h;
    h.insert(78);
    h.insert(23);
    h.insert(25);
    h.insert(1);
    h.insert(89);
    h.print();
    h.deletefromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout << "Printing heap. " << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;

    cout << "Priority queue here ! <Max Heap>"  << endl;
    priority_queue<int> pq;
    
    pq.push(35);
    pq.push(74);
    pq.push(2738);
    pq.push(32);
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    if(pq.empty()){
        cout << "Heap is empty! " << endl;
    }else{
        cout << "Heap is not empty! " << endl;
    }

    //// min heap
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(35);
    minheap.push(74);
    minheap.push(2738);
    minheap.push(32);
    cout << "Top element: " << minheap.top() << endl;
    minheap.pop();
    cout << "Top element: " << minheap.top() << endl;
    minheap.pop();
    if(minheap.empty()){
        cout << "Min-Heap is empty! " << endl;
    }else{
        cout << "Min-Heap is not empty! " << endl;
    }

}