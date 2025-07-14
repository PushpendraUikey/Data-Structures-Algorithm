#include <bits/stdc++.h>
using namespace std;

/*
Given an array we need to find the Longest subarray with alternate even odd elements
*/

int longestEvenOdd(vector<int>&arr){
    int cnt = 1;
    int maxi = 1;
    int n = arr.size();

    for(int i=1; i<n; i++){
        if(arr[i]%2 == arr[i-1]%2){
            cnt = 1;
        }else{
            cnt++;
            maxi = max(maxi, cnt);
        }
    }

    return maxi;
}