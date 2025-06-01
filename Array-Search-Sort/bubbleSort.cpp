#include<bits/stdc++.h>
using namespace std;

// In each i'th round we place the largest element in the end.

void BubbleSort(int arr[], int n){

    for(int i{0}; i < n; i++){
        bool swapped = false;

        int e = n - i - 1; 

        if(e < i) break;

        for(int j{i}; j < e; j++){
            if(arr[j] > arr[j+1]) {
                swapped  = true;
                swap(arr[j], arr[j+1]);
            }
        }
        
        if(!swapped){       // If no swap done that means array has become sorted.
            break;
        }
    }
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i{0}; i< n; i++) cin >> arr[i];

    BubbleSort(arr, n);

    for(int i{0}; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
}