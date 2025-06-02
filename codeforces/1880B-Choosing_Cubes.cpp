#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


void check(vector<int> & arr, int n, int f , int k){
    int size = arr.size();
    int ele = arr[f-1];
    sort(arr.begin(), arr.end(), greater<int>());

    if(k == size){
        cout << "YES" << endl;
    }
    else if(arr[k] < ele) cout << "YES" << endl;
    else if( arr[k] == ele && k >= 1 && arr[k-1] == ele) cout << "MAYBE" << endl;
    else cout << "NO" << endl; 
}
int main(){
    int t; cin>> t;
    while (t--> 0)
    {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> arr;
        for(int i{0}; i<n; i++){
            int x; cin >> x;
            arr.push_back(x);
        }
        check(arr, n, f, k);
    }
    
}
