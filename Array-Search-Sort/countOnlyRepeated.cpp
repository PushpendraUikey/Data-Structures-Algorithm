#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of n positive integers, where elements are consecutive (sorted). 
Also, there is a single element which is repeating x(any variable) number of times. 
Now, the task is to find the element which is repeated and number of times it is repeated.
Note: If there's no repeating element, Return {-1,-1}.

elements: k, k+1, k+2, ..., k+j, k+j, ..ptimes, k+j+1, k+j+2, ...
*/

class Solution {
  public:
    pair<long, long> findRepeating(long *arr, int n) {
        long beg = arr[0];
        int b=0, e=n-1;
        int m;
        long repeating = -1;
        while(b <= e){
            m = b + (e-b)/2;
            if(arr[m] == arr[m+1]){
                repeating = arr[m];
                break;
            }
            else if ( arr[m] == m+beg ){    // Sequence is good so far!
                b = m + 1;
            }
            else{                           // repeating ele is in the first half
                e = m - 1;
            }
        }
        
        if(repeating == -1){
            return {-1, -1};
        }
        
        auto last = upper_bound(arr, arr+n, repeating);
        auto first = lower_bound(arr, arr+n, repeating);
        
        return {repeating, last-first};
    }
};