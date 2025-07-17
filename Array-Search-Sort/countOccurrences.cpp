#include <bits/stdc++.h>
using namespace std;

// In a sorted array we need to find the occurrences of a number "x" given to us. 
// There's this trick of using builtin methods "lower_bound" and "upper_bound"
// but here we'll use the modified binary search to find the number of occurences;

int first_occurrence(vector<int>&arr, int x){
    int n = arr.size();
    int b = 0, e = n-1;
    int m;

    while(b <= e){
        m = b + (e-b)/2;

        if(arr[m]==x && (m==0 || arr[m-1] < x)){
            return m;
        }
        else if(arr[m] >= x){
            e = m - 1;
        }
        else{
            b = m + 1;
        }
    }
    return m;
}

int last_occurrence(vector<int>&arr, int x){
    int n=arr.size();
    int b = 0, e = n-1;
    int m;
    while(b <= e){
        m = b + (e-b)/2;
        if(arr[m]==x && (m==n-1 || arr[m+1] > x)){
            return m;
        }
        else if(arr[m] <= x){
            b = m + 1;
        }
        else{
            e = m - 1;
        }
    }
    return m;
}

int count_occurrences(vector<int>&arr, int x){
    int i = first_occurrence(arr, x);
    int j = last_occurrence(arr, x);
    return (j-i+1);
}