#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at 
most one element in the subarray.
Note: After skipping the element, the subarray must still be non-empty.
*/

class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return arr[0];
        
        vector<int> fw(n), bw(n);
        
        fw[0] = arr[0];
        for(int i=1; i<n; i++){
            fw[i] = max(fw[i-1]+arr[i], arr[i]);
        }
        bw[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            bw[i] = max(bw[i+1]+arr[i], arr[i]);
        }
        
        int maxim = *max_element(fw.begin(), fw.end()); // Normal maxi without skipping
        
        for(int i=1; i<n-1; i++){
            maxim = max(maxim, fw[i-1]+bw[i+1]);
        }
        
        return maxim;
    }
};