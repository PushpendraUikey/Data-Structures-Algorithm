#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find the maximum and minimum of k-sized window in array
*/

int solve(int *arr, int n, int k){
    deque<int> maxi(k); // automatically initializes with int's default value which is 0;
    deque<int> mini(k);
    // Addition of first k size window
    for(int i=0; i<k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    for(int i=k; i<n; i++){
        ans += arr[maxi.front()] + arr[mini.front()];

        /// Removal
        while(!maxi.empty() && i-maxi.front() >= k){
            maxi.pop_back();
        }
        while(!mini.empty() && i-mini.front() >= k){
            mini.pop_back();
        }

        /// Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    /// make sure to consider the last window
    ans += arr[maxi.front()] + arr[mini.front()];
    
    return ans;
}