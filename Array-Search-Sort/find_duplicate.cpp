#include<iostream>
using namespace std;

//// Only one duplicate is in the array O(n^2) algorithm

int findDuplicate(int* arr, int s){
    int i{0};
    while(i<(s-1)){
        int ans=arr[i];
        for(int k{i+1}; k<s;k++){
            if(ans^arr[k]==0) return ans;
        }
        i++;
    }
    return 0;
}

int main(){
    int l; cin >> l;
    int arr[l];
    for(int i{0}; i<l; i++) cin >> arr[i];
    cout << "Duplicate in the array is: " << findDuplicate(arr,l)<< endl;
}