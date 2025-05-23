#include <bits/stdc++.h>
using namespace std;

// Following algorithm tells whether the sum of two numbers in an array is equal to the given target in 
// O(nlogn)

bool __twosum(std::vector<int>&arr, int&target){
    std::sort(arr.begin(), arr.end());

    int b=0, e=arr.size()-1;
    while(b<e){
        int sum = arr[b]+arr[e];
        if(sum == target) return true;
        if(sum > target) e--;
        else b++;
    }
    return false;
}