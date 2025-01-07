#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to solve the phonebook problem
Given a string containing digits of keypad find the all possible combination of output 
strings possible.
*/


class Solution {
private:
    void solve(string digits, string output, string mapping[], vector<string> & ans, int i){
        if(i==digits.size()){   // an output found then store it.
            ans.push_back(output);
            return;
        }

        int num = digits[i] - '0';
        string req = mapping[num];

        for(int j{0}; j<req.size(); j++){
            output.push_back(req[j]);
            solve(digits, output, mapping, ans, i+1);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string output;
        string mapping[10] = {"","", "abc", "def","ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
        int i = 0;
        solve(digits,output, mapping, ans, i);
        return ans;
    }
};