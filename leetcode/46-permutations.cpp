#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<vector<int>>&ans, vector<int>&temp, vector<int>&arr, int idx){
        if(temp.size() == arr.size()){
            ans.push_back(temp);
            return;
        }

        int n = arr.size();
        int j=0; 
        for(int i=idx%n; j<n; j++, i=(i+1)%n) {
            int val = arr[i];
            if(val != INT_MAX){
                temp.push_back(val);
                arr[i] = INT_MAX;
                solve(ans, temp, arr, i+1);
                temp.pop_back();
                arr[i] = val;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, nums, 0);
        return ans;
    }
};


class Solution {
    void solve(vector<vector<int>>&ans, vector<int>&arr, int idx){
        if(idx == arr.size()){
            ans.push_back(arr);
            return;
        }

        int n = arr.size();
        for(int i=idx; i<n; i++) {
            swap(arr[i], arr[idx]);
            solve(ans, arr, idx+1);
            swap(arr[i], arr[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }
};