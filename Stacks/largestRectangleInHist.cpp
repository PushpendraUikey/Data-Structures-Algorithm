 #include<bits/stdc++.h>
 using namespace std;
 
/*
Algorithm to solve the problem of maximum rectangle area
*/

/*for every element this function finds the first previous index which has smaller value than current one.*/
 vector<int> prevSmallerElement(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for(int i = 0; i<n; i++){
        while(st.size() != 1){
            if(arr[st.top()]<arr[i]) break;  // For next greater element just reverse the sign.
            st.pop();
        }
        int v = arr[i];
        ans[i] = st.top();

        st.push(i);
    }
    return ans;
 }
 /*for every element first next smaller element index this function gives.*/
 vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for(int i = n-1; i>=0; i--){
        while(st.size() != 1){
            if(arr[st.top()]<arr[i]) break;
            st.pop();
        }
        int v = arr[i];
        ans[i] = st.top();

        st.push(i);
    }
    return ans;
 }
 
 int largestRectangle(vector < int > & heights) {
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = 0;

    for(int i=0; i<n; i++){
      int l = heights[i];
      if(next[i]==-1){
        next[i] = n;
      }
      int b = next[i]-prev[i]-1;
      int newArea = l*b;
      area = max(area, newArea);
    }

    return area;
 }