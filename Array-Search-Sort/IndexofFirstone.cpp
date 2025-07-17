#include <bits/stdc++.h>
using namespace std;


// Finding the index of first one in the 0-1 sorted array.

int index_of_Firstone(vector<int>&arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int mid;

    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid]==1 && (mid==0 || arr[mid-1] == 0)){
            return mid;
        }
        else if(arr[mid] == 1){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return mid;
}