#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to check if the paranthesis in a string are valid or not
*/

bool matches(char &ch, char &t) {
  if (ch == '(' &&t == ')')
    return true;
  if (ch == '{' &&t == '}')
    return true;
  if (ch == '[' &&t == ']')
    return true;

    return false;
}

bool isValidParenthesis(string s)
{
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }else{
            if(!st.empty()){
                char top = st.top();
                if(matches(top, ch)){
                    st.pop();
                }else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()) return true;
    return false;
}