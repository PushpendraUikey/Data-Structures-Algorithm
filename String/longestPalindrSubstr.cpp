#include<bits/stdc++.h>
using namespace std;

////// Here is the brute force approach to get the longest palindromic substring from the given string

bool ispalindrome(string &str, int i, int e){
    while(i<e){
        if(str[i] != str[e]) return false;
        i++;
        e--;
    }
    return true;
}
string longestPalinSubstring(string str) {
    int e = str.length()-1;
    string ans;
    int maxlen = 0;

    for(int i=0 ; i <= e; i++ ){
        for(int j=e; j>=i; j--){
            if(ispalindrome(str, i, j)){
                int len = j-i+1;
                if(len > maxlen){
                    maxlen = len;
                    ans = str.substr(i, maxlen);
                }
            }
        }
    }
    if(ans.empty()) ans = str[0];
    
    return ans;
}