#include <bits/stdc++.h>
using namespace std;

// We need to find out if the number has two consecutive 1's in binary representation
class Solution {
  public:
    // Function to check if the number is sparse or not.
    bool isSparse(int n) {
        int last = n%2;
        n >>= 1;
        while(n){
            if(n%2&last) return false;
            last = n%2;
            n>>=1;
        }
        return true;
    }
};