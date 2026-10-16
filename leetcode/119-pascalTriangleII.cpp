#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        prev.push_back(1);

        for(int i=1; i<=rowIndex; i++) {
            vector<int> tmp;
            tmp.push_back(1);

            for(int j=1; j<i; j++) {
                tmp.push_back(prev[j-1]+prev[j]);
            }

            tmp.push_back(1);
            prev = tmp;
        }
        return prev;
    }
};