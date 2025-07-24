#include <bits/stdc++.h>
using namespace std;

/*
Ishaan is playing with strings these days. He has found a new string. He wants to modify it as 
per the following rules to make it valid:

The string should not have three consecutive same characters (Refer example for explanation).
He can add any number of characters anywhere in the string. 
Find the minimum number of characters which Ishaan must insert in the string to make it valid.
*/

class Solution {
  public:
    // Function to find minimum number of characters which Ishaan must insert
    // such that string doesn't have three consecutive same characters.
    int modified(string a) {
        // Your code here
        int lastch = '\0';
        int cnt=0;
        int total=0;
        for(int i=0; i<a.length(); i++){
            if(a[i] != lastch){
                lastch = a[i];
                cnt=1;
            }else{
                cnt++;
                if(cnt>2){
                    total++;
                    cnt=1;
                }
            }
        }
        return total;
    }
};