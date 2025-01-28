#include <bits/stdc++.h>
using namespace std;

// given an array and fixed size k < n, you have to find the maximum sum of subarray of size k;

int maxsum(std::vector<int>&arr, int k){
    int sum = std::accumulate(arr.begin(), arr.begin()+k, 0);
    int m = sum;
    for(int i=0; i<arr.size()-k; i++){
        sum += arr[i+k] - arr[i];
        m = std::max(m, sum);
    }
    return m;
}