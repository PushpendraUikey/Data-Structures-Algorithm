#include<bits/stdc++.h>
using namespace std;

// In the given array all the number occurs even number of times except two numbers, find those
// ofcourse the naive solution of O(n^2) will do the job well.
std::pair<int,int> twoOddoccur(vector<int>&arr){
    int val = arr[0];
    for(int i=1; i<arr.size(); i++){
        val ^= arr[i];
    }
    int k = val & ~(val-1); // right most bit will remain

    // Now the logic to solve the problem is that since all the elements are
    // XOR'ed so the final value that came up is XOR of the two odd occuring 
    // hence all the bits are only occuring in any one of two in "val" and 
    // not in both simultaneously.

    int res1=0, res2=0;
    for(int i=0; i<arr.size(); i++){
        if(k&arr[i]){
            res1 ^= arr[i];
        }else{
            res2 ^= arr[i];
        }
    }

    return {res1, res2};
}