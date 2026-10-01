#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<string>&ans, string s, string curr, int b) {
        if(s.empty() && b == 0){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if(s.empty() || b <= 0) return;

        string single = s.substr(0, 1);
        if((s.length()-1)/b <= 3)
            solve(ans, s.substr(1), curr + single + ".", b-1);

        string twodig = s.substr(0, 2);
        int v1 = stoi(twodig);
        if((s.length()-2)/b <= 3 && v1 > 9 && v1 < 100)
            solve(ans, s.substr(2), curr + twodig + ".", b-1);
        
        string thrdig = s.substr(0, 3);
        int val = stoi(thrdig);
        if((s.length()-3)/b <= 3 && val < 256 && val > 99)
            solve(ans, s.substr(3), curr + thrdig + ".", b-1);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(ans, s, "", 4);
        return ans;
    }
};