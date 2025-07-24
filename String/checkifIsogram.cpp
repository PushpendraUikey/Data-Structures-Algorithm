#include <bits/stdc++.h>
using namespace std;

/*
Given a string S of lowercase alphabets, check if it is isogram or not. An Isogram is a 
string in which no letter occurs more than once.
*/

class Solution {
  public:
    // Function to check if a string is Isogram or not.
    bool isIsogram(string s) {
        set<char>st;
        if(s.length()>26) return false;
        
        for(int i=0; i<s.length(); i++){
            if(st.find(s[i]) != st.end()) return false;
            st.insert(s[i]);
        }
        
        return true;
    }
};