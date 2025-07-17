#include <bits/stdc++.h>
using namespace std;

// The arrays of size n has elements 1,2,..,n in which one element is missing and one is repeating
// There are several ways to solve the problem two common being sorting O(nlogn) and hashing O(n) with
// extra space of O(n)

// Here we'll be using negative indexing

pair<int,int> MissingRepeating(vector<int>&arr){
    int repeating=-1, missing=-1;
    int n=arr.size();
    int temp;
    for(int i=0;i < n; i++){
        temp = arr[abs(arr[i])-1];
        if(temp < 0){
            repeating = abs(arr[i]);
        }
        else{
            arr[abs(arr[i])-1] = -temp;
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            missing = i+1;
            break;
        }
    }

    return make_pair(repeating, missing);
}