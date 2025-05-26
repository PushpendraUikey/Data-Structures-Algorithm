#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., 
every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x_1,x_2,...,x_n: the contents of the array.
Output
Print the minimum number of moves.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    unsigned long long arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    unsigned long long cnt = 0;
    unsigned long long largest = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] < largest){
            cnt += (unsigned long long)(largest - arr[i]);
        }
        largest = max(largest, arr[i]);
    }
    cout << cnt << "\n";
}