#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s1 and s2. Modify both the strings such that all the common characters of s1 and s2 
are to be removed and the uncommon characters of s1 and s2 are to be concatenated.
Note: If all characters are removed print -1.
*/

class Solution {
  public:
    // Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) {
        vector<int> vec1(26,0), vec2(26,0);
        for(int i=0; i<s1.length(); i++){
            vec1[s1[i]-'a']++;
        }
        for(int i=0; i<s2.length(); i++){
            vec2[s2[i]-'a']++;
        }
        
        char c;
        string ans = "";
        for(int i=0; i<s1.length(); i++){
            c = s1[i];
            if(vec2[c-'a']==0) ans += c;
        }
        for(int i=0; i<s2.length(); i++){
            c = s2[i];
            if(vec1[c-'a']==0) ans += c;
        }
        
        if(ans.empty()) ans="-1";
        return ans;
    }
};