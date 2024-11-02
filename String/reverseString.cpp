#include<bits/stdc++.h>
using namespace std;

// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        for(int i=0; i<len; i += 2*k){
            int e = min(i+k-1, len-1);
            int b = i;
            while(e > b) {
                if(e>=len) e = len-1;
                swap(s[b], s[e]);
                b++;
                e--;
            }
        }
        return s;
    }
};

// simply reverse the char vector in place
class Solution1 {
public:
    void reverseString(vector<char>& s) {
        int e = s.size()-1;
        int b = 0;
        while(e>b){
            swap(s[e], s[b]);
            b++;
            e--;
        }
    }
};