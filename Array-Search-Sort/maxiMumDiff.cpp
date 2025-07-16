#include <bits/stdc++.h>
using namespace std;

// In this problem we've to find out the maximum arr[j]-arr[i] such that j >= i;

// It's strict condition j > i can be used in the problems like "Buy and Sell Stock!"
// In that strict condition the second loop inside for would run first.

int maxDiff(vector<int>&arr){
    int n = arr.size();

    int mini = arr[0];
    int maxDff = 0;
    for(int i=0; i<n; i++){
        mini = min(mini, arr[i]);
        maxDff = max(maxDff, arr[i]-mini);
    }
    return maxDff;
}