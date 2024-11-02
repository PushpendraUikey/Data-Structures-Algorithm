#include<bits/stdc++.h>
using namespace std;

/// @brief  very effficient algorithm to solve the maximum length of valid paranthesis problem where we can solve the problem in O(n)
///  Parantheses consists of '(' and  ')'

class Solution{
public:
    int maxLength(string s){
    
    stack<int> st;
    st.push(-1);
    int matched_length = 0;
    int size = s.length();
  
  for(int i=0; i < size; i++){
    if(s[i]=='('){
      // len++;
      st.push(i);
      
    }else{
    //// ) encountered while there is no ( 
    st.pop();
      if(!st.empty()){
        matched_length = max(i - st.top(), matched_length);
      }else{
          //// base for next sequence
        st.push(i);
      }
    }
  }
  return matched_length;
    }
};