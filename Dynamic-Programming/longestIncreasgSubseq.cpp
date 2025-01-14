#include <bits/stdc++.h>
using namespace std;

// Here is the idea
// To calculate a value of length(k), we should find a position i<k for which
// array[i]<array[k] and length(i) is as large as possible. Then we know that
// length(k)=length(i)+1, because this is an optimal way to add array[k] to a
// subsequence.

class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(vector<int>& arr) {
        vector<int> length(arr.size());
        for(int i=0; i<arr.size(); i++){
            length[i] = 1;
            for(int j=0; j<i; j++){
                if(arr[j] < arr[i]){
                    length[i] = max(length[i], length[j]+1);// finding the max Longest subseq at 'i' from prev built subsequences
                }
            }
        }
        
        int maxi=1;
        for(auto& e: length){
            if(e>maxi) maxi = e;
        }
        
        return maxi;
    }
};