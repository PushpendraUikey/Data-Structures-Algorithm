#include <bits/stdc++.h>
using namespace std;

// Leaders in array are the elements right to which there's no greater element
// This problem can be solved using next greater element (stack) approach


vector<int> leaders(vector<int>&arr){
    int n = arr.size();
    vector<int> ans;
    int gr = arr[n-1];

    ans.push_back(gr);

    for(int i=n-2; i>=0; i--){
        if(arr[i] > gr){
            gr = arr[i];
            ans.push_back(gr);
        }
    }

    return gr;
}