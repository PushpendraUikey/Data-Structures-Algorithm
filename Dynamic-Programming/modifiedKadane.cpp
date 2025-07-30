#include <bits/stdc++.h>
using namespace std;
/*
You are given an array arr of size sizeOfArr. You need to find the maximum sum in the array provided 
that you cannot sum neighboring elements or adjacent elements.
*/

typedef long long ll;

class Solution {
  public:
    // Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int sizeOfArray) {
        if(sizeOfArray==1) return arr[0];
        vector<ll>maxSum(sizeOfArray,0);
        
        maxSum[0]=(ll)arr[0]; 
        maxSum[1] = max((ll)arr[1], (ll)arr[0]);
        // maxSum[1] = (long long) arr[1];
        
        for(int i=2; i < sizeOfArray; i++){
            maxSum[i] = max<ll>((ll)max<ll>(maxSum[i-1], maxSum[i-2]+arr[i]), arr[i]);
            // maxSum[i] = (long long)arr[i];
            // for(int j=0; j<=i-2; j++){
            //     maxSum[i] = max<long long>(maxSum[j]+arr[i],maxSum[i]);
            // }
        }

        return maxSum[sizeOfArray-1];
    }
};