#include<bits/stdc++.h>
using namespace std;

/*
Solution to famous celebrity problem, where we've to find a potential celebrity which is known by 
everyone and who doesn't know anyone M[a][b] is true if a knows b, and false if a do not know b.
*/

class Solution 
{   
    private:
    bool knows(vector<vector<int> >& M, int &a, int &b){
        if(M[a][b]) return true;
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        while(st.size() != 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(knows(M,a,b)){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        int c = st.top();
        for(int i=0; i<n; i++){
            if(i==c) continue;
            if(knows(M,i,c) && !knows(M, c, i)) continue;
            return -1;
        }
        return c;
    }
};