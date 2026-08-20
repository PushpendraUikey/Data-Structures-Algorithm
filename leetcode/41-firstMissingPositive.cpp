#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();

        for(int i=0; i<n; i++) {
            while(arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i]-1] ){
                swap(arr[arr[i]-1], arr[i]);
            }
        }
        int i=0;
        for( ; i<n; i++) {
            if(arr[i] != i+1) return i+1;
        }

        return i+1;
    }
};