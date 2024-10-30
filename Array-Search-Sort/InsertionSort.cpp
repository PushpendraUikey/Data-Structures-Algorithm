#include<bits/stdc++.h>
using namespace std;

// Using the insertion sort
void insertionSort(int arr[], int k){
    for(int i{0}; i < k; i++){
        int temp = arr[i];
        int j;

        for( j = i-1; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];  // Do shift the elements here.  
            }else{
                break;
            }
        }

        arr[j+1] = temp;    // when condition become false for the loop, j would have already dicremented

    }
}