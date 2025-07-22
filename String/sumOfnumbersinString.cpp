#include <bits/stdc++.h>
using namespace std;

/*
Given a string str containing alphanumeric characters. 
The task is to calculate the sum of all the numbers present in the string.
*/
class Solution {
    inline bool isChar(char c){
        return (c>='a'&&c<='z') || (c>='A'&&c<='Z');
    }
  public:
    // Function to calculate sum of all numbers present in a string.
    int findSum(string& s) {
        int total = 0;
        int i=0;
        while(i<s.length()){
            if(!isChar(s[i])){
                int num=0;
                while(i<s.length() && !isChar(s[i])){
                    num = num*10 + (s[i++]-'0');
                }
                total += num;
            }
            i++;
        }
        return total;
    }
};