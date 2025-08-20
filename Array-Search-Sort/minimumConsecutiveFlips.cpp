/*
Given a binary array, we need to convert this array into an array that either contains all 1s or all 0s.  
We need to do it using the minimum number of group flips. 
*/

#include <bits/stdc++.h>
using namespace std;

void printGroups(vector<bool>&bitstring){
    int n = bitstring.size();

    for(int i=1; i<n; i++){
        if(bitstring[i] != bitstring[i-1]){
            if(bitstring[i] != bitstring[0]){
                cout << "From " << i << " to ";
            }else{
                cout << i-1 << endl;
            }
        }
    }
    if(bitstring[n-1] != bitstring[0]){
        cout << n-1 << endl;
    }
}