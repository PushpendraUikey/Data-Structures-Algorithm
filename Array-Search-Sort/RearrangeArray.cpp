#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of size n where every element is in the range from 0 to n-1. 
Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].
NOTE: arr and arrT are both same variables, representing the array before and after 
transformation respectively.
*/

// In this solution, the important trick that we used here is encoding that is, updating the current values
// with the ability to retrieve both the previous and new value at the same time.

class Solution {
  public:
    void arrange(vector<long long>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            arr[i] += (arr[arr[i] % n] % n) * n;
        }
        
        for(int i=0; i<n; i++){
            arr[i] /= n;
        }
    }
};