#include<bits/stdc++.h>
using namespace std;

// Sorting by selecting min-index again and again.

void SelectionSort(int arr[], int n){
    for(int i{0}; i< n - 1; i++){
        int minIndex = i;
        for(int j{i+1}; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int n; cin >> n;
    int arr[n]; 
    for(int i{0}; i<n; i++) cin >> arr[i];

    SelectionSort(arr, n);
    for(int i{0}; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

}