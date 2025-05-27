/*
Problem: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(const char& c){
        return (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
public:
    int maxVowels(string s, int k) {
        int j=0;
        char c;
        int curwindow=0, globlmax=0;
        for(; j<k; j++){
            c = s[j];
            if( (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' ) ){
                curwindow++;
                globlmax++;
            }
        }
        for( ; j<(int)s.length(); j++){
            c = s[j];
            if ( (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' ) ){
                curwindow++;
            }
            c = s[j-k];
            if( (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u') ){
                curwindow--;
            }
            globlmax = max(curwindow, globlmax);
        }

        return globlmax;
    }
};