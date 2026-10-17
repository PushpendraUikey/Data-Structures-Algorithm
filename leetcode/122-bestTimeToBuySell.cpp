#include <bits/stdc++.h>
using namespace std;

// Book profit whenever there is an ascent in price
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            if (n == 0) return 0;
            int profit = 0;

            for(int i=1; i<n; i++) {
                if(prices[i] - prices[i-1] > 0) {
                    profit += (prices[i] - prices[i-1]);
                }
            }
            return profit;
        }
};