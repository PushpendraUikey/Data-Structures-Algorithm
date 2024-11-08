#include<bits/stdc++.h>
using namespace std;

/*
Given an array `price[]` of stock prices over `n` days, find the **stock span** for each day.
The span of a stock’s price on a day is the number of consecutive days (up to that day) with 
prices less than or equal to that day’s price. Return the spans as an array.

Example:
Input: `price = [100, 80, 60, 70, 60, 75, 85]`  
Output: `span = [1, 1, 1, 2, 1, 4, 6]`
*/

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int> st;
       vector<int> ans;
       
       for(int i=0; i<n; i++){
           ans.push_back(i+1);
           while(!st.empty()){
               if(price[st.top()] > price[i]){
                   ans[i] = i - st.top();
                    break;
               }
               st.pop();
           }
           st.push(i);
       }
       
       return ans;
    }
};