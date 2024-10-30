#include <bits/stdc++.h> 
using namespace std;
long long threeWaySplit(int n, vector<int> arr){
    // Write your code here.

    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;
    long long ans = 0, ssum = arr[0], esum = arr[e];

    while(e > s){
        if(ssum == esum){
            ans = ssum;
            s++; e--;
            ssum += arr[s];
            esum += arr[e];
        }else if( ssum < esum){
            s++;
            ssum += arr[s];
        }else{
            e--;
            esum += arr[e];
        }
    }
    return ans;
}

int main(){
    int t; cin >> t;
    vector<long long> ans;
    int n;
    while(t-->0){
        cin >> n;
        vector<int> temp(n);
        for(int i{0}; i< n; i++) cin >> temp[i];

        ans.push_back(threeWaySplit(n , temp));
    }

    for(int i{0}; i< ans.size() ; i++){
        cout << ans[i] << endl;
    }
}