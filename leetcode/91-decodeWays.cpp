#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string s, set<string>&st, vector<int>&memo) {
        if(s.empty()) return 1;
        int n =  s.length();
        if(memo[n] != -1) return memo[n];
        
        int result = 0;
        string first = s.substr(0,1);
        if(st.count(first) > 0) {
            result += solve(s.substr(1), st, memo);
        }
        if(s.length() > 1) {
            string second = s.substr(0,2);
            if(st.count(second) > 0) {
                result += solve(s.substr(2), st, memo);
            }
        }

        return memo[n] = result;
    }
public:
    int numDecodings(string s) {
        set<string> st;
        int n = s.length();
        vector<int> memo(n+1, -1);
        for(int i=1; i<=26; i++) {
            st.insert(to_string(i));
        }

        return solve(s, st, memo);
    }
};

// A faster O(n) solution using DP
int numDecodings(string s) {
    int n = s.length();
    if(n == 0 || s[0] == '0') return 0; // no valid decoding if the string is empty or starts with '0'

    int prev1 = 1; // dp[i-1]
    int prev2 = 1; // dp[i-2]

    for(int i=1; i<n; i++) {
        int current = 0;

        if(s[i] != '0') {
            current += prev1; // single digit decoding
        }

        int twoDigits = (s[i-1] - '0') * 10 + (s[i] - '0');
        if(twoDigits >= 10 && twoDigits <= 26) {
            current += prev2;
        }

        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}