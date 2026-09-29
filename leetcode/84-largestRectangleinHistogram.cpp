#include <bits/stdc++.h>
using namespace std;

class Solution {
    void prev(vector<int>&arr, vector<int>&ans){
        stack<int> st;
        st.push(-1);

        for(int i=0; i<arr.size(); i++){
            while(st.size() > 1){
                int idx = st.top();
                if(arr[idx] >= arr[i]) st.pop();
                else break;
            }
            ans[i] = st.top();
            st.push(i);
        }
    }
    void next(vector<int>&arr, vector<int>&ans){
        stack<int> st;
        st.push(ans.size());

        for(int i=arr.size()-1; i>=0; i--) {
            while(st.size() > 1){
                int idx = st.top();
                if(arr[idx] >= arr[i]) st.pop();
                else break;
            }
            ans[i] = st.top();
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevsmall(n);
        vector<int> nextsmall(n);
        prev(heights, prevsmall);
        next(heights, nextsmall);

        int maxRect = 0;
        for(int i=0; i<n; i++) {
            int ps = prevsmall[i];
            int ns = nextsmall[i];
            int rectarea = heights[i] * (ns - ps - 1);
            if(rectarea > maxRect) maxRect = rectarea;
        }

        return maxRect;
    }
};

// Single pass solution
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxRect = 0;
    int n = heights.size();

    for (int i=0; i<=n; i++) {
        int currHeight = (i==n) ? 0 : heights[i];

        while(!st.empty() && currHeight < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();

            // Width is determined by the current index (right boundary)
            // and new stack top (left boundary)
            int width = st.empty() ? i : i - st.top() - 1;
            maxRect = max(maxRect, height * width);
        }
        st.push(i);
    }

    return maxRect;
}