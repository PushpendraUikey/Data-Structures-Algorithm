#include <bits/stdc++.h>
using namespace std;

/*
You are given an array 'arr' of length 'n'. Find the index(0-based) of a peak
element in the array. If there are multiple peak numbers, return the index of any peak number.
Peak element is defined as that element that is greater than both of its neighbors. 
If 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.
Assume 'arr[-1]' and 'arr[n]' as negative infinity.

Note:
1.  There are no 2 adjacent elements having same value (as mentioned in the constraints).
2.  Do not print anything, just return the index of the peak element (0 - indexed).
3. 'True'/'False' will be printed depending on whether your answer is correct or not.
*/

int findPeakElement(vector<int> &arr) {
    // Write your code here
	int n = arr.size();
	int b = 0, e = n-1;
    int m;
    while(b <= e){
        m = b + (e-b)/2;

        if( (m==0 || (arr[m] > arr[m-1])) && ( m == n-1 || (arr[m] > arr[m+1]))){
            return m;
        }
        else if( m>0 && (arr[m] < arr[m-1])){
           
            e = m - 1;
        }else{
            b = m + 1;
        }
    }
    return -1;
}

/*
Approach:

Using Binary Search, check if the middle element is the peak element or not. If the middle element 
the peak element terminate the while loop and print middle element, then check if the element on the 
right side is greater than the middle element then there is always a peak element on the right side. 
If the element on 
the left side is greater than the middle element then there is always a peak element on the left side. 
*/