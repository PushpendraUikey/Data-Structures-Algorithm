#include <bits/stdc++.h>
using namespace std;

/*
Given a binary array(0/1), we'll be counting the maximum number of consecutive 1's in the array.
*/

int maxiOnes(vector<int>&arr){
    int n = arr.size();

    int cnt=0;
    int maxi = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            cnt = 0;
        }else{
            cnt++;
            maxi = max(maxi, cnt);
        }
    }

    return maxi;
}