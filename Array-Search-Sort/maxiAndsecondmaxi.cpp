#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> largestAndSecondLargest(vector<int> &arr) {
        // code here
        int maxi=-1, secondmaxi = -1;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > maxi){
                secondmaxi = maxi;
                maxi = arr[i];
            }else if(arr[i] != maxi && arr[i]>secondmaxi){
                secondmaxi = arr[i];
            }
        }
        
        return {maxi, secondmaxi};
    }
};