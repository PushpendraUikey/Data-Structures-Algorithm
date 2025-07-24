#include <bits/stdc++.h>
using namespace std;

// In this problem we've to return the total number of subsets whose sum is equal to the given SUM value

int subsetsum(int i, vector<int>&arr, int sum){
    if(i<0){
        return sum==0? 1:0;
    }

    return subsetsum(i-1, arr, sum) + subsetsum(i-1, arr, sum-arr[i]);
}