#include <bits/stdc++.h>
using namespace std;

// In this proble we move all the zeroes in the array to the end with 
// relative ordering of the remaining elements keeping them same
void moveZeroinEnd(vector<int>& arr){
    int cnt=0;
    int i=0;
    int n = arr.size();
    for( ; i<n ;i++){
        if(arr[i] != 0){
            arr[cnt++] = arr[i];
        }
    }
    for( ; cnt<n; cnt++){
        arr[cnt] = 0;
    }
}