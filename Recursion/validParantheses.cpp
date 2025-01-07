#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool charMatch(char & ch, char & c){
        if(ch == '(' && c == ')') return true;
        else if(ch == '{' && c == '}') return true;
        else if(ch == '[' && c == ']') return true;
        else return false;
    }
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        if(len%2 != 0) return false;

        for(int i{0}; i<len; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(!charMatch(st.top(), s[i])){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};