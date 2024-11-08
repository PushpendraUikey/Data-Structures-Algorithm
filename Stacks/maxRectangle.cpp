#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;

/*
Solution to maximum area finding problem
*/
class Solution{
    private:
    vector<int> nextSmallelement(int * arr,int n){
        vector<int> ans(n); stack<int> st; st.push(-1);
        for(int i=n-1; i>=0; i--){
            while(st.size() != 1){
                if(arr[st.top()] < arr[i]) break;
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallelement(int *arr,int n){
        vector<int> ans(n); stack<int> st; st.push(-1);
        for(int i=0; i < n; i++){
            while(st.size() != 1){
                if(arr[st.top()] < arr[i]) break;
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int area(int* arr, int n){
        vector<int> prevsmall = prevSmallelement(arr, n);
        vector<int> nextsmall = nextSmallelement(arr, n);
        int maxarea = 0;
        for( int i=0; i<n; i++){
            int h = arr[i];
            int l = prevsmall[i];
            int r = nextsmall[i];
            if(r==-1) r = n;
            int area = h*(r-l-1);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxarea = area(M[0], m);
        for(int i =1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j] == 1)
                M[i][j] = M[i][j] + M[i-1][j];
                else {
                    M[i][j] = 0;
                }
            }
            maxarea = max(maxarea, area(M[i], m));
        }
        return maxarea;
    }
};