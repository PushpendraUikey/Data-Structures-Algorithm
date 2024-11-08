#include<bits/stdc++.h>
using namespace std;

/*
This function removes up to `k` elements from `arr` to maximize the remaining sequence.
It uses a stack to keep only larger elements in sequence order, then returns the result as a vector.
*/

vector<int> deleteElement(vector<int>& arr, int k) {
    int size = arr.size();
    
    vector<int> ans;
    stack<int> st;
    
    for(int i=0; i<size; i++){
        while(k>0 && !st.empty() && st.top() < arr[i]){
            st.pop();
            k--;
        }
        st.push(arr[i]);
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}