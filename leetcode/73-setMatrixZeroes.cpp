#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        while(!rows.empty()){
            auto it = rows.begin();
            int idx = *it;
            rows.erase(it);

            for(int j=0; j<n; j++){
                matrix[idx][j] = 0;
            }
        }

        while(!cols.empty()){
            auto it = cols.begin();
            int idx = *it;
            cols.erase(it);

            for(int i=0; i<m; i++) {
                matrix[i][idx] = 0;
            }
        }
    }
};