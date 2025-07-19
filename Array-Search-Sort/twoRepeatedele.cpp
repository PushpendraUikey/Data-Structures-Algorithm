#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer n and an integer array arr of size n+2. All elements of the 
array are in the range from 1 to n. 
Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
Note: Return the numbers in their order of appearing twice. So, if x and y are repeating numbers, 
and x's second appearance comes before the second appearance of y, then the order should be (x, y).
*/

// Whenever the array elements are or solution seem to be bound by the size of the array and we need the repeting
// we can always use the trick of negative indexing to get those elements.

class Solution {
  public:
    vector<int> twoRepeated(int n, int arr[]) {
        int num1=0, num2=0;
        
        for(int i=0;i < n+2; i++){
            int curr = abs(arr[i]);
            if( arr[curr-1] > 0){
                arr[curr-1] = -arr[curr-1];
            }else{  // if arr[curr-1] is already neg then curr is repeated
                if(num1==0){
                    num1 = curr;
                }else{
                    num2 = curr;
                }
            }
        }
        
        return {num1, num2};
    }
};