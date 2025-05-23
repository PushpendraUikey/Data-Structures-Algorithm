#include <bits/stdc++.h>
using namespace std;

// a problem where we are given an array of n positive
//  integers and a target sum x, and we want to find a subarray whose sum is x or
//  report that there is no such subarray.
// Given implementation gives the number of such subarrays

int _subarrSum(std::vector<int>&arr, int&x){
    int sum =0;
    int fast = 0, slow = 0;
    int cnt=0;
    if(x < 0) return cnt;
    while(fast < arr.size()){
        sum += arr[fast++];
        while(sum > x && slow < fast){
            sum -= arr[slow++];
        }
        if(sum == x) cnt++;
    }
    return cnt;
}