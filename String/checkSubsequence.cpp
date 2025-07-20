#include<bits/stdc++.h>
using namespace std;

/*
Given two strings A and B, find if A is a subsequence of B. A subsequence is a sequence that can be derived 
from another sequence by deleting some elements without changing the order of the remaining elements.
*/

class Solution {
  public:
    bool isSubSequence(string A, string B) {
        int n = A.length();
        int m = B.length();
        
        int i=0, j=0;
        
        if(n>m) return false;
        
        while(i<n && j<m){
            if(A[i]==B[j]){
                i++; 
                j++;
            }
            else{
                j++;
            }
        }
        return i==n;
    }
};