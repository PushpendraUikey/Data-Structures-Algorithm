#include<bits/stdc++.h>
using namespace std;

/*
Algorithms to merge two heaps.
*/

void heapify(vector<int>& arr, int& n, int e){
    arr.push_back(e);
    int i = n;
    n++;

    while(i>0){
        int parent = (i-1)/2;   /// Since child Node for any node is 2*i+1;
        if(arr[i] > arr[parent]){
            swap(arr[i], arr[parent]);
            i = parent;
        }else{
            return;
        }
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    for(int i=0; i<m; i++){
        heapify(arr1, n , arr2[i]);
    }
    return arr1;
}


////////////  Alternate Solution which is more faster.

void heapify(vector<int>& arr, int& n, int e){  // recursive heapify
    int l = e;
    int left = 2 * e + 1;
    int right = 2 * e + 2;

    if(left < n && arr[l] < arr[left]){
        l = left;
    }
    if(right < n && arr[l] < arr[right]){
        l = right;
    }
    if(l != e){
        swap(arr[e], arr[l]);
        heapify(arr, n, l);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    
    for(auto& i:arr2){
        arr1.push_back(i);              // push all the elements into one array.
    }

    int size = arr1.size();

    for(int i = size/2; i>=0; i--){     // Heapify the array( this is heapify algorithm )
        heapify(arr1, size, i);
    }
    return arr1;
}