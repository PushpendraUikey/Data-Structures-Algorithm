#include<bits/stdc++.h>
using namespace std;

// Problem here is that in a rotated sorted array, we have to find out the pivot element.

int getPivot(int arr[], int n){
    int s=0;
    int e{n-1};

    if(arr[0] < arr[e]) return e;       // non rotated array

    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){              // updating after comparing with constant 
            s = mid+1;
        }else{
            e = mid;        // to get the pivot element(starting element, which is also the lowest)
        }
        mid = s + (e-s)/2;
    }
    return arr[mid];
}

int main(){
    int arr[] = {8, 9, 45, 333, 2, 4, 5, 6, 7};
    int s = sizeof(arr)/sizeof(arr[0]);

    cout << getPivot(arr, s) << endl;
}


// Another implementation to find pivot could be as
// following implementation gives maxima of function
int findPivot(int (*f(int)), int z){
    int x =-1;
    for (int b = z; b >= 1; b /= 2) {
    while (f(x+b) < f(x+b+1)) x += b;
    }
    int k = x+1;
}