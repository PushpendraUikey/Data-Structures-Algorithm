#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //  Function to find the gray code of given number n
    int greyConverter(int n) {
        int last;
        int grey=0;
        int j=0;
        while(n){
            last = n%2;
            n >>= 1;
            grey |=( (n%2)^last ) * (1<<j);
            j++;
        }
        return grey;
    }
};