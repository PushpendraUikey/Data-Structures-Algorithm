#include <bits/stdc++.h>
using namespace std;

/*
You are given two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of 
the string s1.
Note: A string is a rotation of another if it can be formed by moving characters from the start to the end 
(or vice versa) without rearranging them.
*/

// This is slight inefficient approach without using addition space.
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        
        if(n!=m) return false;
        
        char f=s1[0];
        int idx=0;
        while(s2.find(f,idx) != string::npos){
            idx = s2.find(f,idx);
            bool iseq=true;
            for(int i=0; i<n; i++){
                if(s1[i] != s2[(i+idx)%n]) iseq=false;
            }
            if(iseq) return true;
            idx++;
        }
        return false;
    }
};

// This approach works in O(n) time and space
// Idea is based on the observation that if s2 is rotation of s1 then it must be present in s1+s1,
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if(s1.length() != s2.length()) return false;
        
        string temp = s1 + s1;
        
        return temp.find(s2) != string::npos;
    }
};