#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1000000007;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int subarr = 0;
        for(int i=0; i<n; i++) {
            int currsum = 0;
            for(int j=i; j<n; j++) {
                currsum += arr[j];
                if(currsum & 1) subarr++;
                subarr = subarr % MOD;
            }
        }

        return subarr;
    }
};