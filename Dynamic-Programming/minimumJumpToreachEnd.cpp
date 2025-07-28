#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers where each element represents the max number of steps that can be made 
forward from that element. Write a function to return the minimum number of jumps to reach the 
end of the array (starting from the first element).

If an element is 0, then cannot move through that element.
*/

/*
we build a jumps[ ] array from left to right such that jumps[ i ] indicates the minimum number of jumps 
needed to reach arr[ i ] from arr[ 0 ]. Finally, we return jumps[ n-1 ].
-> Bottom Up tabulation! : Optimal Substructure Property!
*/
int miniJumpsToReachEnd(const vector<int>&arr){
    int n = arr.size();
    if(n==0 || arr[0]==0) return INT_MAX;

    vector<int> jumps(n,INT_MAX);
    jumps[0] = 0;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            // look if jumps[j]==INT_MAX but we can reach i using j (i<=j+arr[j]), still j isn't reachable from 0
            if( i <= j+arr[j] && jumps[j] != INT_MAX){
                jumps[i] = min(jumps[i], jumps[j]+1);
                break;
            }
        }
    }
    
    return jumps[n-1];
}