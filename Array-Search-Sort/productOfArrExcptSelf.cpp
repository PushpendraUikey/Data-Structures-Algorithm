#include <bits/stdc++.h>
using namespace std;

// Given an array as input, we need to return an array with product of all the elements except the 
// current given index.

// O(n^2) Inefficient solution!
vector<int> productExceptSelf_ineff(const vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        int pdt = 1;
        for(int j=0; j<n; j++){
            if(i!=j) pdt *= arr[j];
        }
        ans[i] = pdt;
    }
}

// slightly efficient with extra space
vector<int> productExceptSelf_eff(const vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n), prefixpdt(n), suffixpdt(n);
    prefixpdt[0] = 1;
    for(int i=1; i<n; i++){
        prefixpdt[i] = prefixpdt[i-1] * arr[i-1];
    }
    suffixpdt[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        suffixpdt[i] = suffixpdt[i+1] * arr[i+1];
    }
    for(int i=0; i<n; i++) ans[i] = prefixpdt[i] * suffixpdt[i];

    return ans;
}

// This is the optimized solution with O(n) TC and O(1) SC
vector<int> productExceptSelf_opt(const vector<int>& arr){
    int n = arr.size();
    int pdt = 1;
    int zeros = 0;
    vector<int> ans(n);
    int idx = -1;

    for(int i=0; i<n; i++){
        if(arr[i]==0) {
            zeros++;
            idx = i;
        }else{
            pdt *= arr[i];
        }
    }
    if(zeros > 1){
        for(int i=0; i<n; i++) ans[i]=0;
    }
    else if(zeros==1){
        for(int i=0; i<n; i++) ans[i]=0;
        ans[idx] = pdt;
    }
    else{
        for(int i=0; i<n; i++){
            ans[i] = pdt/arr[i];
        }
    }
    
    return ans;
}