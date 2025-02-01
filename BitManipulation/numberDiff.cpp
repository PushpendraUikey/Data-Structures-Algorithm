#include <bits/stdc++.h>
using namespace std;

// GFG contest 189: Problem 1

// You are given a number n. Your task is to calculate the difference between n and its inverted
// number.
// The inverted number of n is obtained by flipping all the bits in the binary representation of n. F
// example, the binary representation of 5 is (101) , and its inverted number is (010) , which is 2 in
// decimal representation

// my solution
class Solution {
  public:
    int numDifference(int n) {
        // code here
        long long inverted = 0;
        long long num = 1;
        int temp = n;
        while(temp){
            if(!(temp&1)){
                inverted += num;
            }
            num *= 2;
            temp = temp >> 1;
        }
        return abs(n - inverted);
    }

// some points to note are, inverted number will always be less and 
    int numDifference2(int n){
        int bitCount = 0;
        int diff = 0;
        while(n){
            if(n&1){
                diff += (1<<bitCount);
            }else{
                diff -= (1<<bitCount);
            }

            bitCount++;
            n >>= 1;
        }
        
        return diff;
    }
};
