#include<iostream>
using namespace std;

// In an array elements are first in increasing order then decreasing order like a mountain, task is to find 
// an element which is the peak of this mountain.

//// Same as to find the pivot element

int main(){
    int n; cin >> n;
    int arr[n]; 
    for(int i{0}; i<n; i++) cin >> arr[i];
    int s{0}, e{n-1};
    int m = s + (e-s)/2;
    while (s<e)
    {
        if(arr[m] < arr[m+1]){
            s = m+1;
        }else{
            e = m;          // Why did we put e = m, is because m will merge towards s. 
        }
        m = s + (e-s)/2;
    }
    cout << "Peak element in the array is : " << arr[m] << endl;
}