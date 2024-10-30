#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        long long int cnt = 0;
        map<long long int, int> mp;
        long long int sum = 0;
        
        for(int i=0; i< n; i++){
            sum += arr[i];
            if(sum == 0) cnt++;
            
            if(mp.find(sum) != mp.end()){
                cnt += mp[sum];
            }
            
            mp[sum]++;
        }
        
        return cnt;
    }
};