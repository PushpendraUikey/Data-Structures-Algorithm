#include<bits/stdc++.h>
using namespace std;

/*
Algorithm removes the element with different sign and tries to make the array beautiful, with same sign
*/
class Solution {
    bool diffsign(int &i, int &j){
        if(i*j < 0) return true;
        else if((i==0 && j<0) || (i<0 && j==0)){
            return true;
        }
        return false;
    }
    public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int> st;
        vector<int> ans;
        int n = arr.size();
        
        for(int i=0; i < n; i++){
            while(!st.empty() && i < n && diffsign(st.top(), arr[i])){
                st.pop();
                i++;
            }
            
            if(i<n) st.push(arr[i]);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        if(!ans.empty()) reverse(ans.begin(), ans.end());
        
        return ans;
    }
};