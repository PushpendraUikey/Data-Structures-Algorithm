#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool inline isAlphaNumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    char processChar(char c) {
        if (c >= 'a' && c <= 'z') return c;
        if (c >= '0' && c <= '9') return c;
        if (c >= 'A' && c <= 'Z') return (char)(c - 'A' + 'a');
        return ' ';
    }

    public:
        bool isPalindrome(string s) {
            int n = s.length();
            if (n == 0) return true;
            for(int i=0; i<n; i++) {
                s[i] = processChar(s[i]);
            }
            int left = 0, right = n-1;
            while(left < right) {
                if(s[left] == ' ') {
                    left++;
                    continue;
                }
                if(s[right] == ' ') {
                    right--;
                    continue;
                }
                if(s[left] != s[right]) return false;
                left++;
                right--;
            }
            return true;
        }
};