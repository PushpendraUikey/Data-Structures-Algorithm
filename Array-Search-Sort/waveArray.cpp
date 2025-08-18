/*
Given an sorted array arr[] of integers. Sort the array into a wave-like array(In Place). In other 
words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5] ..... 
and so on. If there are multiple solutions, find the lexicographically smallest one.

Note: The given array is sorted in ascending order, and modify the given array in-place without 
returning a new array.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n/2; i++){
            swap(arr[2*i], arr[2*i+1]);
        }
    }
};