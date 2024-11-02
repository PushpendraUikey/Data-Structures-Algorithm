#include <bits/stdc++.h> 
using namespace std;

///// algorithm tells if the expression contains a redundant bracket in given string
//// ex (a*b+(c+d)+(l)), the bracket around 'l' is redundant

bool isoperator(char &ch){
    if(ch == '+' || ch == '*' || ch == '/' || ch == '-') return true;
    return false;
}
bool findRedundantBrackets(string &s)
{
    int len = s.length();
    stack<char> st;

    for(int i=0; i<len; i++){

        char ch = s[i];

      if (ch == '(' || isoperator(ch)) {
        st.push(s[i]);
      } else if (ch == ')') {
          bool hasOperator = false;
        while(!st.empty() && st.top() != '('){
            char top = st.top();
            st.pop();

            if(isoperator(top)){
                hasOperator = true;
            }
        }

        if(!hasOperator) return true;

        st.pop();   // removing '('
      }
    }

    return false;   // no redundant bracket found

}