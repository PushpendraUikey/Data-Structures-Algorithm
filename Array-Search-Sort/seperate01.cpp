#include<iostream>
using namespace std;

// seperating 0's and 1's of an array using two pointer approach.

int main(){
    cout << "Give the n followed by n 0/1: ";
    int n; cin >> n;
    int arr[n];
    for(int i{0}; i<n; i++) cin >> arr[i]; 
    int i{0}, j{n-1};
    while(i<=j){
        if(arr[i]==0) i++;
        else if(arr[j]==1) j--;
        else if(arr[i]==1&&arr[j]==0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    for(int k{0}; k<n; k++){
        cout << arr[k] << ' ';
    }
    cout << endl;
}