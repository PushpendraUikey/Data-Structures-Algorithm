#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s1 and s2 consisting of only lowercase English letters and of equal length, 
check if these two strings are isomorphic to each other.
If the characters in s1 can be changed to get s2, then two strings, s1 and s2 are isomorphic. 
A character must be completely swapped out for another character while maintaining the order of 
the characters. A character may map to itself, but no two characters may map to the same character.
*/

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        if(s1.length() != s2.length()) return false;
        
        unordered_map<char, char> mp;
        set<char> st;
        char c,d;
        int n = s1.length();
        
        for(int i=0; i<n; i++){
            c=s1[i];
            d=s2[i];
            
            if(mp.find(c)!=mp.end()){   // if char in s1 points some char
                if(mp[c] != d) return false; // but not the current indexed char
            }
            else if(st.find(d) != st.end()){ // if it is already pointed by some other char
                return false;
            }else{
                mp[c] = d;
                st.insert(d);
            }
        }
        
        return true;
    }
};