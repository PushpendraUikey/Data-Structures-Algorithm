#include <bits/stdc++.h> 
using namespace std;

/*
Minimum cost to make a string valid, which consists of these charachters '{' and '}'. 
*/

int findMinimumCost(string str) {
    if(str.length() & 1) return -1; // not possible to make valid

    stack<char> ans;

    for(int i=0; i<str.length(); i++){
      char ch = str[i];
      
      if(ch == '{'){
        ans.push(ch);
      } else {
        if (!ans.empty() && ans.top() == '{'){  //// this case ignores already valid paranthesis
          ans.pop();
        } else {
          ans.push(ch);
        }
      }
    }
    
      // Stack contains invalid expression.
    int a = 0; int b = 0;
      while(!ans.empty()){
        if(ans.top() == '{') b++;
        else a++;
        ans.pop();
      }
    return (a+1)/2 + (b+1)/2;
}