#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& arr, int n){
    int s = 0; int e = n-1;
    if(arr[s] < arr[e]) return 0;

    int m = s + (e - s)/2;
    while(s < e){
       
        if(arr[s] <= arr[m]){
            s = m +1;
        }else {
            e = m;
        }
        m = s + (e-s)/2;
    }
    if(arr[s-1] < arr[s]) return s-1;
    return s;
}
int binary_search(vector<int>& arr, int s, int e, int k){
    int m = s + (e-s)/2;

    while(s <= e){
        if(arr[m] == k) return m;
        else if(arr[m] < k) s = m + 1;
        else e = m-1;
        m = s + (e - s)/2;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr,n);
    int ans;
    if(k <= arr[n-1]){
        ans = binary_search(arr, pivot, n-1, k);
    }else{
        ans = binary_search(arr, 0, pivot-1, k);
    }
    return ans;
}

int main(){
    int n, k; cin >> n >> k;
    vector<int> arr;
    for(int i{0}; i<n;i++) {
        int c; cin >> c;
        arr.push_back(c);
    }
    cout << search(arr, n, k) << endl;
}