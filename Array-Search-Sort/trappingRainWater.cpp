#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] with non-negative integers representing the height of blocks. 
If the width of each block is 1, 
compute how much water can be trapped between the blocks during the rainy season. 
*/
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> leftmax(n), rightmax(n);
        
        // PreComputation!
        leftmax[0] = arr[0];
        for(int i=1 ; i < n; i++){
            leftmax[i] = max(arr[i], leftmax[i-1]);
        }
        rightmax[n-1] = arr[n-1];
        for(int j=n-2; j>=0; j--){
            rightmax[j] = max(arr[j], rightmax[j+1]);
        }
        
        int water=0;
        for(int i=0; i<n; i++){
            water += min(leftmax[i], rightmax[i]) - arr[i];
        }
        
        return water;
    }
};