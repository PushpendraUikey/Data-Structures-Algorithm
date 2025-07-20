#include <bits/stdc++.h>
using namespace std;

/*
A lucky number is defined using a special elimination process:
   1. Start with natural numbers: 1, 2, 3, 4, 5, 6, ...
   2. In the 1st step, remove every 2nd number.
   3. In the 2nd step, remove every 3rd remaining number.
   4. In the 3rd step, remove every 4th remaining number, and so on...
This continues indefinitely. Given an integer n, determine if it remains after all steps.
Return 1 if n is a lucky number, otherwise return 0.
*/

// The solution is based on the core insight that at each step we're tracking the position of n 
// in the list instead of tracking the entire list. If n falls at multiple of i'th position that 
// means it was going to be removed from the original list and if it escaped then
// we remove the n/i elements ahead of it at positions multiple of i. Then we go for i+1. 
// and if i surpasses n then it n was not gonna be removed from the list.

class Solution {
    bool solve(int n, int i){
        if(n%i==0) return false;
        if(i > n) return true;
        return solve(n-n/i, i+1);
    }
  public:
    bool isLucky(int n) {
        return solve(n, 2);
    }
};