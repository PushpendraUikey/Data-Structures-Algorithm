#include <bits/stdc++.h>
using namespace std;

// The array is sorted and rotated to some rotation value and we need to find 
// an element in it. We'll use binary search with modification to find that element
// This approach is an alternative to the Pivot finding then doing binary search approach


int findelement(vector<int>&arr, int x){
    int n=arr.size();
    int low=0, high = n-1;
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if( arr[mid] == x ) return mid;
        if( arr[low] <= arr[mid] ){     // Left half sorted
            if ( x >= arr[low] && x <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else {                         // Right half sorted
            if( x >= arr[mid] && x <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}