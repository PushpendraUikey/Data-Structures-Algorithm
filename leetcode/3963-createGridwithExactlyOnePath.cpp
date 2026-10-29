#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s(n, '.');
        ans.push_back(s);

        for(int i=0; i<n-1; i++) s[i] = '#';
        for(int i=0; i<m-1; i++) ans.push_back(s);

        return ans;
    }
};