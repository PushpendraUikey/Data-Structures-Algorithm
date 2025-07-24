#include <bits/stdc++.h>
using namespace std;

/*
Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.
*/

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        vector<int> vec(26,0);
        for(int i=0; i<s.length(); i++){
            vec[s[i]-'a']++;
        }
        for(int i=0; i<s.length(); i++){
            if(vec[s[i]-'a']==1) return s[i];
        }
        return '$';
    }

    // slight optimization and can be used for streams as well
    char nonRepeatingChar1(string&s){
        vector<int> vec(26,-1);
        int v;
        for(int i=0; i<s.length(); i++){
            v = s[i]-'a';
            if(vec[v]==-1){ // first occurrence
                vec[v] = i;
            }else{  // it is repeating
                vec[v] = -2;
            }
        }
        int mini = INT_MAX;
        int res = -1;
        for(int i=0; i<26; i++){
            if(vec[i] >= 0){
                if(mini > vec[i]){
                    mini = vec[i];
                    res = i;
                }
            }
        }
        return mini == INT_MAX ? '$' : (char)('a'+ i);
    }
};