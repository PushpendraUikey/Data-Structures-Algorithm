#include <bits/stdc++.h>
using namespace std;

// You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.
// Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be 
// chosen any number of times from the array 'ARR'.
// Elements in each combination must be in non-decreasing order.

void solve(int s, vector<vector<int>>&ans, vector<int>&arr, vector<int>&result, int sum){
    if(sum == 0){
        ans.push_back(result);
        return;
    }
    for(int i=s; i<arr.size(); i++){
        if(arr[i] > sum){
            break;  // since sorted(this path doesn't lead to the solution)
        }
        result.push_back(arr[i]);
        solve(i, ans, arr, result, sum-arr[i]);
        result.pop_back();  // back-track it.
    }
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    vector<vector<int>> ans;
    std::sort(ARR.begin(), ARR.end());

    vector<int> result;
    solve(0, ans, ARR, result, B);
    return ans;
}