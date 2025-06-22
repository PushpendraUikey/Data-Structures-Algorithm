#include <bits/stdc++.h>
using namespace std;

// In given array as input all the numbers are even time occuring except this one 
// number which occurs odd times.
int oddoccuring(vector<int>&arr){
    int res = arr[0];
    for(int i=1; i<arr.size(); i++){
        res ^= arr[i];
    }
    return res;
}