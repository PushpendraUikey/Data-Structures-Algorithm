#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rem = 1;
        int val = 0;
        int sz = digits.size();
        for(int i=sz-1; i>=0; i--) {
            val = digits[i] + rem;
            digits[i] = val%10;
            rem = val/10;
        }
        if(rem==0) return digits;

        vector<int> ans(sz+1);
        for(int i=1; i<=sz; i++) ans[i] = digits[i-1];
        ans[0] = rem;
        return ans;
    }
};