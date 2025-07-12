#include <bits/stdc++.h>
using namespace std;

/*
Reversing an array in group of some number!
*/

class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        int i=0,  j = k-1;
        int fact = 0;
        int n = arr.size();   
        while(i < n){
            fact++;
            j = min(j, n-1);
            while(i<j){
                swap(arr[i], arr[j]);
                i++;j--;
            }
            i = k*fact;
            j = k + k*fact-1;
        }
    }
};
