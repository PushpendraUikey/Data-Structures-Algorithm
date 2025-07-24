#include <bits/stdc++.h>
using namespace std;


/*
Given a string s consisting of only uppercase and lowercase characters. The task is to sort uppercase 
and lowercase letters separately such that if the ith place in the original string had 
an Uppercase character then it should not have a lowercase character after being sorted and vice versa.
*/

class Solution {
    inline bool isUpper(char c){
        return c>='A' && c<='Z';
    }
  public:
    string caseSort(string& s) {
        string temp ="";
        string lower="";
        for(int i=0; i<s.length(); i++){
            if(isUpper(s[i])){
                temp += s[i];
            }else{
                lower += s[i];
            }
        }
        sort(temp.begin(), temp.end());
        sort(lower.begin(), lower.end());
        int j=0, k=0;
        
        for(int i=0; i<s.length(); i++){
            if(isUpper(s[i])){
                s[i] = temp[j++]; 
            }else{
                s[i] = lower[k++];
            }
        }
        
        return s;
    }
};