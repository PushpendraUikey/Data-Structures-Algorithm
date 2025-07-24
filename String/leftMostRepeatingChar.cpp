#include <bits/stdc++.h>
using namespace std;

/*
You are given a string S (both uppercase and lowercase characters). 
You need to print the index of repeated character whose first appearance is leftmost.
*/

class Solution {
  public:
    // Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter(string s) {
        unordered_map<char, int> mp;
        int idx=-1;
        for(int i=s.length()-1; i >= 0; i--){
            if(mp.find(s[i]) != mp.end()){
                idx=i;
            }
            else{
                mp[s[i]] = i;
            }
        }
        
        return idx;
    }
};