#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] denoting the cost of stock on each day, the task is to find the m
aximum total profit if we can buy and sell the stocks any number of times.
Note: We can only sell a stock which we have bought earlier and we cannot hold multiple 
stocks on any day.
*/

// When price is going up let it go and take the diff between dip and peak, when price is going down
// let it go and don't do anything there. 
// In the solution we're in general adding cumulative profits to make up for the difference of one day
// buy and later day sell.

class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        int profit = 0;
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1]){
                profit += (arr[i] - arr[i-1]);
            }
        }
        
        return profit;
    }
};