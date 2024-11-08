#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find the first next smaller element for any element.
loop iteration begins from the end.
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    for(int i = n-1; i>=0; i--){
        while(st.size() != 1){
            if(st.top()<arr[i]) break;  /////// For next greater element just reverse the sign.
            st.pop();
        }
        int v = arr[i];
        arr[i] = st.top();

        st.push(v);
    }
    return arr;
}