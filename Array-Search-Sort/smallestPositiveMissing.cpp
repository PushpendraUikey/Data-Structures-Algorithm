#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer array arr[]. Your task is to find the smallest positive n
umber missing from the array.
Note: Positive number starts from 1. The array can have negative integers too.
*/

// The positive number missing can't be more than n+1, So in solution we're trying to 
// place a positive number x in the position x-1 if it is under suitable bounds. 

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        for(int i=0;i < n; i++){
            while(arr[i]>0 && arr[i]<=n && arr[arr[i]-1] != arr[i]){
                int t = arr[i];
                arr[i] = arr[t-1];
                arr[t-1] = t;
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i] != i+1) return i+1;
        }
        
        return n+1;
    }
};