#include <bits/stdc++.h>
using namespace std;

// You are given two strings s and t, consisting only of lowercase English letters. You are allowed to
// perform the following operation on string s:
// Choose an index i (0 ≤ i < |s|) and insert a new character immediately after the i
// character. The newly inserted character must be different from ith charachter.
// Determine whether t can be achieved using given actions(possibly zero)


class Solution {
  public:
    bool isPossible(string &s, string &t) {
        
        int i=0; int j=0; 
        int n = s.size(); int m = t.size();
        
        // prefixes must be same with equal frequency of same char
        while(i<n && j<m && t[j] == s[0]){
            if(s[i] != t[j]){
                return false;
            }
            i++, j++;
        }
        
        // edge case in which first string exhaust.
        if(j>=n && j<m && s[0] == t[j]) return false;
        
        // checking if subsequence!!
        while(i<n && j<m){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        
        return i==n;
    }
};