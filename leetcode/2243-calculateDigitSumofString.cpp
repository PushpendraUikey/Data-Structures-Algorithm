#include <bits/stdc++.h>
using namespace std;

class Solution {
    string solve(string s){
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            ans += (s[i] - '0');
        }
        return to_string(ans);
    }
public:
    string digitSum(string s, int k) {
        string ans = s;
        while(ans.length() > k){
            string temp = ans;
            string tans = "";
            for(int i=0; i<ans.length(); i+=k) {
                tans += solve(temp.substr(i, k));
            }
            ans = tans;
        }

        return ans;
    }
};


class Solution {
public:
    string digitSum(string s, int k) {
        string ans = s;
        while(ans.length() > k){
            string next = "";
            int n = ans.length();
            for(int i=0; i<n; i+=k) {
                int tsum = 0;
                for(int j=i; j<min(i+k, n); j++){
                    tsum += (ans[j]-'0');
                }

                next += to_string(tsum);
            }
            ans = next;
        }

        return ans;
    }
};