#include <bits/stdc++.h>
using namespace std;

// Given two integers dividend and divisor, divide two integers without using 
// multiplication, division, and mod operator.

class Solution {
public:
    int divide(int dividend, int divisor) {

        if(divisor == -1 && dividend == INT_MIN) return INT_MAX;

        int isneg = (divisor < 0) ^ (dividend < 0);

        long n = labs(dividend);
        long d = labs(divisor);
        long quotient = 0;

        while(n >= d) {
            long temp = d;
            long multiple = 1;

            while(n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            quotient += multiple;
        }

        if(isneg) return -quotient;
        return quotient;
    }
};