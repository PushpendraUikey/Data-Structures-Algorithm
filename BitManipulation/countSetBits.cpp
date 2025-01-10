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