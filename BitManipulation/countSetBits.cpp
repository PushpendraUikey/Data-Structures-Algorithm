#include <bits/stdc++.h>

// You are given a positive integer ‘N’. Your task is to find the total number of ‘1’ in the 
// binary representation of all the numbers from 1 to N.
// Since the count of ‘1’ can be huge, you are required to return it modulo 1e9+7.

int countSetBits(int n) {
    int cnt=0;
    int mod = 1e9+7;

    while(n>0){
        // method to count bits '1' in a number is
        // a g++ compiler method
        cnt = (cnt+__builtin_popcount(n))%mod;
        n--;
    }
    return cnt;
}

// following methods are supported by g++ compiler
/*
 • __builtin_clz(x): the number of zeros at the beginning of the number
 • __builtin_ctz(x): the number of zeros at the end of the number
 • __builtin_popcount(x): the number of ones in the number
 • __builtin_parity(x): the parity (even or odd) of the number of ones

 While the above functions only support int numbers, there are also long long
 versions of the functions available with the suffix ll
*/

// Here's the Naive approach to find the set bits in a given number: TC = O(log2_n)
int setbits(int n){
    int res = 0;
    while(n>0){
        res = res + (n&1);
        n >>= 1;
    }
    return res;
}

// Here's more optimized version: TC = O(setbits)
// Brian Kernighan’s Algorithm
int setbits1(int n){
    int res = 0;
    while(n){
        res++;
        n = n & (n-1);  // This operation sets off the last set bit in the number from right
    }
    return res;
}

// For large number of set bits queries: ex setbits in num from 1 to n
int setbits2(int n){

    // lookup table
    int bitstable[256];
    bitstable[0] = 0;
    for(int i=1; i<256; i++){
        bitstable[i] = (i&1) + bitstable[i/2];
    }
    // Alternative
    // for(int i=1; i<256; i++){
    //     bitstable[i] = bitstable[(i&(i-1))] + 1;
    // }

    int cnt = 0;

    for(int i=1; i<=n ; i++){
        cnt += ( bitstable[i & 255 ] +
                 bitstable[(i>>8) & 255] +
                 bitstable[(i>>16) & 255] +
                 bitstable[(i>>24) & 255]
                );
    }
    return cnt;
}


// Here's the very efficient algorithm to count all the set bits from 1 to n. Uses a formula
class Solution {

  public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        if(n==0) return 0;
        
        int x = log2(n);    // Highest power of 2 <= n
        int bitsupto2x = x * (1<<(x-1));    // set bits in [1, 2^(x-1)]: This is the formula to remember!
        int msbBits = n - (1 << x) + 1;     // Set bits in MSB from 2^x to n.
        int rest = n - (1 << x);    // remaining numbers.
        return bitsupto2x + msbBits + countSetBits(rest);
    }
};
