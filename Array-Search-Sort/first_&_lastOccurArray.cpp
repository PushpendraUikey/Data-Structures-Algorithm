#include<iostream>
#include<vector>
using namespace std;

// Problem is to find out the first and last occur, of any element in a sorted array, if not present return -1;
// Time complexity: O(log n);
// Divide the problem in two parts, first half to iterate check for first indx and second for last indx, use
// Binary Search

/*
!Warning: The approach given here is very naive;
a better solution exists in some other file in this directory
Use binary search again and again till you find first and last occurance


Refer to the: noOfOccur.cpp
*/
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> ans;
        int i{-1}, j{-1};
        int start = 0;
        int end = n-1;
        int mid = start + (end-start)/2;
        while(start<=end){
            if(arr[mid]==x){
                i = mid;
                /* Warning: Segfault possible */
                while(arr[mid]==x) i = mid;// Instead of running loop, you can still some optimization by making i = mid and end = mid-1;
                break;
            }else if(arr[mid]>x){
                end = mid-1;
            }else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        if(i==-1){
            ans.push_back(i); ans.push_back(i);
            return ans;
        }
        start = 0;
        end = n-1;
        mid = start + (end-start)/2;
        while(start<=end){
            if(arr[mid]==x){
                j = mid;
                /* Warning: Segfault possible */
                while(arr[++mid]==x) j = mid;   // Instead of running loop, you can still some optimization by making j = mid and start = mid+1;
                break;
                
            }else if(arr[mid]>x){
                end = mid-1;
            }else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        ans.push_back(i); ans.push_back(j);
        
        return ans;
    }
};