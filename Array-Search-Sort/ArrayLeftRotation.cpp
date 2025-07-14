#include <bits/stdc++.h>
using namespace std;

// Left rotation of array is counterclock wise movement of elements in circular way

void leftRotateBy1(vector<int>&arr){
    int temp = arr[0];
    int i=1, n = arr.size();

    for( ; i<n ;i++){
        arr[i-1]  = arr[i];
    }

    arr[n-1] = temp;
}

// theta(D) auxilliary space!
void leftRotateByD(vector<int>&arr, int d){
    vector<int> temp(d);
    int i=0, n = arr.size();

    for( ; i<d; i++){
        temp[i] = arr[i];
    }
    for( ; i<n ; i++){
        arr[i-d] = arr[i];
    }
    for(i=0; i<d; i++){
        arr[n-d+i] = temp[i];
    }
}

// theta(1) auxilliary space
void Reverse(vector<int>&arr, int low, int high){
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void leftRotateByD_effi(vector<int>&arr, int d){
    int n = arr.size();
    Reverse(arr, 0, d-1);
    Reverse(arr, d, n-1);
    Reverse(arr, 0, n-1);
}