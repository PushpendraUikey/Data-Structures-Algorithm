#include <bits/stdc++.h>
using namespace std;

// Goal in this exercise is to return the minimum length of subarray whose sum reaches the Target.

// First we'll derive an O(n^3) algorithm then start optimizing it.
int __subarr1(std::vector<int>&vec, int&T){
    int n = vec.size();
    for(int len=1; len<n; len++){
        for(int j{0}; j<n-len-1; j++){
            
            int sum = 0;
            for(int i=j; i<j+len-1; i++){
                sum += vec[i]; 
            }

            if(sum >= T) return len;
        }
    }

    return -1;
}

// Now we deduce the O(n^2) algorithm,

int __subarr2(std::vector<int>&vec, int&T){
    int sum = 0;
    int n = vec.size();
    for(int l=1; l<n; l++){
        sum += vec[l-1];
        int tempsum = sum;
        for(int i=0; i<n-l-1; i++){
            if(tempsum>=T) return l;
            tempsum += vec[i+l]-vec[i];
        }
    }
    return -1;
}

// Here's how we'll do it O(nlogn) time using ubiqutous Binary Search Algorithm!
// current implimentation just accounts for minimum length and not for the actual subarray itself.
// so it can be updated for each starting point calculate the minimum length of subarr meeting requirements
int __subarr3(std::vector<int>&vec, int&T){
    // first we need to precompute the prefix sum which'll make our work a lot more easier.
    int n = vec.size();
    std::vector<int> prefixsum(n+1,0);
    int temp=0;
    
    for(int i=0; i<n; i++){
        prefixsum[i+1] = prefixsum[i] + vec[i];
    }

    // now Getting the required length with the help of Binary search
    int s=0, e = n-1;
    int result = INT_MAX;

    while(s<e){
        int l = s + (e-s)/2;
        bool areWegood = false;

        for(int i=0; i<=n-l-1; i++){
            int sum = prefixsum[i+l] = prefixsum[i];
            if(sum >= T){
                areWegood = true;
                break;
            }
        }

        if(areWegood){
            result = l; // update the result.
            e = l-1;
        }else{
            s = l+1;
        }
    }
    return (result == INT_MAX) ? -1 : result;
}

// There's an very efficient O(n) algorithm as well.