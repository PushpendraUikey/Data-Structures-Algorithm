#include <bits/stdc++.h>
using namespace std;

/*
You are given a sorted array of ‘N’ distinct integers that are in the Arithmetic Progression sequence 
except for one element which is missing from the sequence. You have to find that missing number from 
the given sequence.

Note:
1. A sequence [arr0, arr1,…, arr(n-1)] is called an Arithmetic progression if for each 'i' ( 0 ≤ i < n - 1) 
the value arr[i+1] − arr[i] is the same. 
2. There is exactly one missing number in the given sequence.
3. All the numbers present in the sequence are distinct.
4. It is the guarantee that the first and last elements of the sequence are not missing elements.
*/

// We're using optimized approach using Binary Search!!!
int missingNumber(vector<int> &arr, int n) 
{
    int d = min((arr[1] - arr[0]), (arr[n-1]-arr[n-2]));
    int low = 0, high = n-1;
    int mid;
    int a = arr[0];
    int ans = 0;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] == a + d * (mid)){
            low = mid+1;
        }else{
            ans = mid;          // last missing index.
            high = mid-1;
        }
    }
    return (a + d * (ans) );
}