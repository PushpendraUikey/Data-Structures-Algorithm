#include <bits/stdc++.h>
using namespace std;

/*
Given a number 'n'. The task is to find the nth number whose each digit is a prime number i.e. 2, 3, 5, 7. 
In other words, you have to find nth number of this sequence: 2, 3, 5, 7, 22, 23 ,... and so on.
*/

/*
Algorithm (Base-4 Approach):
Consider the prime digits as characters in base-4:
0 → 2
1 → 3
2 → 5
3 → 7
Convert (n-1) to base-4.
Replace base-4 digits with corresponding prime digits.
*/

class Solution {
  public:
    // Function to find nth number made of only prime digits.
    int primeDigits(int n) {
        vector<int> primeDigits = {2, 3, 5, 7};
        n--;// for zero based indexing
        int result = 0;
        int temp = 1;
        while(n>=0){
            result = primeDigits[n%4] * temp + result;
            temp *= 10;
            n = n/4 - 1;
        }
        return result;
    }
};