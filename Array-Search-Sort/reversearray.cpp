#include<iostream>
using namespace std;

// DON"T REPEAT YOURSELF

void ReverseArray(int a[], int size){
    int R = size -1;
    for(int i{0}; i < size/2; i++){
        int r = a[i]; 
        a[i] = a[R-i];
        a[R-i] = r;
    }
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i{0}; i<n; i++){
        cin >> arr[i];
    }

    int max{arr[0]},min{arr[0]}; // One more thing you can do here is that, initialize min to INT_MAX and max to INT_MIN, bcz they worth it.

    for(int i{0}; i<n; i++){
        if(arr[i]<min) min = arr[i];    // There are already defined function here as well, max = max(max, arrli])
        if(arr[i]>max) max = arr[i];    // min = min(min, arr[i]);     max() and min() already defined function with two arguments 
    }
    cout << "Max of the arrays is: " << max << " and min of array is: " << min << endl;
    ReverseArray(arr,n);
    for(int i{0};i<n; i++)
        cout << arr[i] << ' ' ;
    cout << endl;
}