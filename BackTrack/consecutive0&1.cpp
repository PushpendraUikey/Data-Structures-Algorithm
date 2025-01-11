#include <bits/stdc++.h>
using namespace std;


// You have been given an integer 'N'. Your task is to generate and return all binary strings of 
// length 'N' such that there are no consecutive 1's in the string.
// A binary string is that string which contains only ‘0’ and ‘1’.



void solve(bool isOne, vector<string>&ans, string&str, int&n){
    if(str.length()==n){
        ans.push_back(str);
        return;
    }
    if(isOne){
        str.push_back('0');
        solve(false, ans, str, n);
        str.pop_back();
    }else{
        str.push_back('0');
        solve(false, ans, str, n);
        str.pop_back();
        str.push_back('1');
        solve(true, ans, str, n);
        str.pop_back();
    }
}
vector<string> generateString(int N) {
    string str="";
    vector<string>ans;

    solve(false, ans, str, N);
    return ans;
}