#include<iostream>
using namespace std;

int main(){
    cout << "Give target element and number of elements for to be in array followed by arrays: " ; 
    int n, k; cin >>k>> n;
    int arr[n];
    for(int j{0}; j<n; j++) cin >> arr[j] ;
    int ans[3];
    for(int p{0}; p<n-2; p++){
        for(int q{p+1}; q<n-1; q++){
            for(int r{q+1}; r<n; r++){
                if((arr[p]+arr[q]+arr[r])==k){
                    ans[0] = p; 
                    ans[1] = q;
                    ans[2] = r;
                }
            }
        }
    }
}