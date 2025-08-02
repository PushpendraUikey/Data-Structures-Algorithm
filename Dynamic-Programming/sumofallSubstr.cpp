#include <bits/stdc++.h>
using namespace std;

/*
Given an integer s represented as a string, the task is to get the sum of all possible sub-strings 
of this string.
Note: The number may have leading zeros.
It is guaranteed that the total sum will fit within a 32-bit signed integer.
*/

class Solution {
  public:
    int sumSubstrings(string &s) {
        int sum = 0;
        int n = s.length();
        
        for(int i=0; i<n; i++){
            int temp=0;
            for(int j=i; j<n; j++){
                temp = temp*10 + (s[j] - '0');
                sum += temp;
            }
        }
        
        return sum;
    }
};

// Here's O(n) Solution to the above problem!
// f(i) = f(i-1) * 10 + (i + 1) * digit_at_i    : This recursive approach is used to crack the problem
// Every digit d at position i appears in exactly (i + 1) substrings that end at i.
// And due to shifting, earlier results get multiplied by 10.
class Solution {
  public:
    int sumSubstrings(string &s){
        int sum = 0;
        int prev = 0;
        int n = s.length();
        
        for(int i=0; i<n; i++){
            int digit = s[i]-'0';
            prev = prev * 10 + digit * (i+1);
            sum += prev;
        }
        
        return sum;
    }
};