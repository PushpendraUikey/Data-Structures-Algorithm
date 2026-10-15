#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> generate(int n){
        vector<vector<int>> ans;
        ans.reserve(n);

        vector<int> prev;
        prev.push_back(1);
        ans.push_back(prev);

        for(int i=2; i<=n; i++) {
            vector<int> tmp;
            tmp.push_back(1);

            for(int j=1; j<i-1; j++) {
                tmp.push_back(prev[j-1]+prev[j]);
            }

            tmp.push_back(1);
            ans.push_back(tmp);

            prev = tmp;
        }

        return ans;
    }
};

class Solution {
    public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i=0; i<numRows; i++){
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;
            for(int j=1; j<i; j++){
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
            res[i][i] = 1;
        }
        return res;
    }
};