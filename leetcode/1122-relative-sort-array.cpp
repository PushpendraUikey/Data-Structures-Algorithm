/*
Problem: https://leetcode.com/problems/relative-sort-array/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int s1 = arr1.size(), s2 = arr2.size();
        int j = 0, num, temp, i, k;
        for(i = 0; i<s2; i++){
            num = arr2[i];
            for(k = j; k < s1; k++){
                if(arr1[k]==num){
                    temp = arr1[j];
                    arr1[j] = arr1[k];
                    arr1[k] = temp;
                    j++;
                }
            }
        }
        for(i = j; i<s1-1; i++){
            for( k = s1-1; k>i; k--){
                if(arr1[k] < arr1[k-1]){        // Bubble sort
                    temp = arr1[k];
                    arr1[k] = arr1[k-1];
                    arr1[k-1] = temp;
                }
            }
        }
        return arr1;
    }
};