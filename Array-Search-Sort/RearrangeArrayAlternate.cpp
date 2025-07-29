#include <bits/stdc++.h>
using namespace std;

/*
Given an array of positive integers. Your task is to rearrange the array elements alternatively 
i.e. first element should be the max value, the second should be the min value, the third should 
be the second max, the fourth should be the second min, and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.
*/

// In this solution, the important trick that we used here is encoding that is, updating the current values
// with the ability to retrieve both the previous and new value at the same time.

class Solution {
  public:
    void rearrange(vector<int>& arr) {
        int n = arr.size();
        int maxi = n-1;
        int mini = 0;
        
        sort(arr.begin(), arr.end());
        int max_element = arr[n-1]+1;
        
        for(int i=0; i<n; i++){
            if(i%2==0){
                arr[i] += (arr[maxi]%max_element)*max_element;
                maxi--;
            }else{
                arr[i] += (arr[mini]%max_element)*max_element;
                mini++;
            }
        }
        
        for(int i=0; i<n; i++){
            arr[i] = arr[i] / max_element;
        }
    }
};