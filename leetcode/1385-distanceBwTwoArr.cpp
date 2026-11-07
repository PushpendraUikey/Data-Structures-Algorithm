#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int distance = 0;

        for (int i=0; i<n1; i++) {

            int v = arr1[i];
            bool found = true;
            for (int j=0; j<n2; j++) {
                if(abs(v - arr2[j]) <= d) {
                    found = false;
                    break;
                }
            }
            if(found) distance++;
        }

        return distance;
    }
};