#include <bits/stdc++.h> 
using namespace std;
// This problem is NP-hard

// You are given an array of integers "ARR" of length 'N' and an integer 'K'. Your task is to find 
// whether or not you can divide the array "ARR" into 'K' subsets with equal sum.
// A subset of an array "ARR" is another array whose every element is present in array "ARR".
// For example
// Consider array ARR = {3, 5, 2, 4, 4} and K = 2, i.e. you have to divide "ARR" into 2 subsets with 
// equal sum. The division will be {4, 5} and {2, 3, 4} with sum 9.
// Note:
// Every element of the array must occupy only one subset.

bool backtrack(int k, int i, vector<bool>&used, int&target, vector<int>&arr, int&currsum){
    if(k==0){
        return true;
    }

    if(currsum == target){
        currsum = 0;
        return backtrack(k-1, 0, used, target, arr, currsum);
    }

    for(int j=i; j<arr.size(); j++){
        if(!used[j] && currsum+arr[j] <= target){
            currsum+=arr[j];
            used[j] = true;
            if(backtrack(k, j+1, used, target, arr, currsum)){
                return true;
            }
            used[j] = false;
            currsum -= arr[j];
        }
        if(!used[j] && currsum==0) break;   // first number doesn't fit that means it can't formed
    }

    return false;
}
bool splitArray(vector<int> &arr, int K) {
    int n =  arr.size();
    vector<bool> used(n, false);
    sort(arr.rbegin(), arr.rend());
    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    if(total_sum%K != 0) return false;
    int target = total_sum/K;
    int currsum = 0;
    
    return backtrack(K,0,used, target,arr, currsum);
}