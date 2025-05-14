#include <iostream>

// Algorithm to solve famous problem Maximum subarray sum in array which contains 
// both positive and negative integers

// Naive O(n^3) solution
int maxsum(int*arr, int n){
    int best=0;
    for(int a=0; a<n; ++a){
        for(int b=a; b<n; ++b){
            int sum=0;
            for(int k=a; k<=b; ++k){
                sum += arr[k];
            }
            best = std::max(best, sum);
        }
    }
    return best;
}

// Algorithm 2, O(n^2) approach 
int maxsum2(int*arr, int n){
    int best=0;

    for(int a=0; a<n; ++a){
        int sum=0;
        for(int b=a; b<n; ++b){
            sum += arr[b];
            best = std::max(best, sum);
        }
    }
}

//// This algorithm is also referred as Kadane's Algorithm
// Algorithm-3;  O(n) approach: Greedy approach
// Consider the subproblem of finding the maximum-sum subarray that ends at
//  position k. There are two possibilities:
//  1. The subarray only contains the element at position k.
//  2. The subarray consists of a subarray that ends at position k 1, followed by
//  the element at position k.
//  In the latter case, since we want to find a subarray with maximum sum, the
//  subarray that ends at position k-1 should also have the maximum sum.Thus we can efficiently 
// solve the maxSubarr sum for each position left to right

int maxsum3(int*arr, int n){
    int best=0, sum=0;
    for(int i=0; i<n; i++){
        sum = std::max(arr[i], sum+arr[i]);
        best = std::max(sum, best);
    }
    return best;
}