#include <bits/stdc++.h>
using namespace std;



// You have been given an integer n. You need to find the count of n-digit numbers formed usi
// the digits from 1 to 9, such that the gcd of the digits of the number is greater than 1.
// Since the answer can be very large, return the answer modulo 10 + 7



// Very efficient method
#define MOD 1000000007
class Solution {
    // Modular arithmetic for power calculation!!!
    long long int power(long long a, long long b){
        long long int ans = 1;
        
        while(b>0){
            if(b&1){
                ans = (ans*a)%MOD;
            }
            a = (a*a)%MOD;
            b >>= 1;
        }
        
        return ans;
    }
  public:
    int countNumbers(long long n) {
// answer is : 4^n[even] + 3^n[3 multiples] - 1[for 6 at all places counts double] + 1[5 at all place] + 1[7 at all place]
        long long int ans = power(4, n)%MOD + power(3,n) + 1;
        ans %= MOD;
        return (int)ans;
    }
};