#include<bits/stdc++.h>
using namespace std;

/// The following program talks about the reversing an equation.

class Solution
{
    bool isOperator(char &ch){
        if(ch == '-' || ch == '+' || ch == '*' || ch == '/'){
            return true;
        }
        return false;
    }
  public:
    string reverseEqn (string s)
        {
            stack<string> st;   // to store other than operators
            stack<char> c;      // to store operators
            string ans = "";
            
            int i=0; int size = s.length();
            
            string req = "";
            
            for(int i=0; i< size; i++){
                while(i<size && !isOperator(s[i])){
                    req += s[i];
                    i++;
                }
                // if string still left then below part will be processed when an operator is encountered.
                if(i<size) c.push(s[i]);
                if(!req.empty()){
                    st.push(req);
                    req = "";
                }
            }
            
            while(!st.empty()){
                ans += st.top();
                st.pop();
                if( !c.empty()){
                    ans += c.top();
                    c.pop();
                }
            }
            
            return ans;
        }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Problem Contributed By: Pranay Bansal
