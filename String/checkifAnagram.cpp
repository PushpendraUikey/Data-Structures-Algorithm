#include <bits/stdc++.h>
using namespace std;

/*
Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine 
whether they are anagrams of each other or not. Two strings are considered anagrams 
if they contain the same characters with exactly the same frequencies, regardless of their order.
*/

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if(s1.length() != s2.length()) return false;
        unordered_map<char, int> mp;
        
        for(int i=0;i < s1.length(); i++){
            mp[s1[i]]++;
            mp[s2[i]]--;
        }
        
        for(const auto& e: mp){
            if(e.second != 0) return false;
        }
        
        return true;
    }
};