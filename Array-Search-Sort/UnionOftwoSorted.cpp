#include<bits/stdc++.h>
using namespace std;


/// @brief  Solution to find the union of two sorted arrays

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        
        int i=0,
        j = 0;
        
        while(i<n || j<m){
            while(i<n-1 && arr1[i] == arr1[1+i]){
                i++;
            }
            while(j<m-1 && arr2[j] == arr2[j+1]){
                j++;
            }
            if(i<n && j<m){
                if(arr1[i] == arr2[j]){
                    ans.push_back(arr1[i]);
                    i++;
                    j++;
                }else if(arr1[i] < arr2[j]){
                    ans.push_back(arr1[i]);
                    i++;
                }else{
                    ans.push_back(arr2[j]);
                    j++;
                }
            }else if(i<n){
                ans.push_back(arr1[i]);
                i++;
            }else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        return ans;
    }
};