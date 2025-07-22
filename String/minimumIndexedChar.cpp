#include <bits/stdc++.h>
using namespace std;

/*
Given a string s1 and another string s2. Find the minimum index of 
the character in s1 that is also present in s2.
*/

class Solution {
  public:
    // Function to find the minimum indexed character.
    int minIndexChar(string &s1, string &s2) {
        vector<int> vec(26,0);
        for(int i=0; i<s2.length(); i++){
            vec[s2[i]-'a'] = 1;
        }
        
        for(int i=0; i<s1.length(); i++){
            if(vec[s1[i]-'a']==1) return i;
        }
        return -1;
    }
};