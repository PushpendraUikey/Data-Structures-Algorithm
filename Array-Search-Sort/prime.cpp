#include<bits/stdc++.h>

// Here is the code to check prime numbers strictly less then a given number 
// this consists of logic to mark all the numbs first prime then, traverse through nums
// if a num is found prime then, remove all the multiples of it from the prime's list.
// It significantly reduces the search span

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        
        vector<bool> Prime(n+1, true);
        Prime[0] = Prime[1] = false;

        for(int i=2; i<n; i++){
            if(Prime[i]){
                count++;
                for(int j = 2*i; j<n; j += i){
                    Prime[j] = false;
                }
            }
        }
        return count;
    }
};