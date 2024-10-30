#include<bits/stdc++.h>
using namespace std;

/// given an array consists of positive integers in which all the elements are present twice except for one which is odd num of times
/// find that odd guy

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        //// XOR'ing
        int num = 0;
        
        for(auto &it:arr){
            num = num ^ it;
        }
        return num;
    }
};