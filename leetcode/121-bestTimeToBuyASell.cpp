#include <bits/stdc++.h>
using namespace std;

// O(n^2) solution
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            if(n == 0) return 0;
            int profit = 0;

            for(int i=1; i<n; i++) {
                for(int j=0; j<i; j++) {
                    if(prices[i]-prices[j] > profit) {
                        profit = prices[i] - prices[j];
                    }
                }
            }
            return profit;
        }
};

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            if(n == 0) return 0;
            int minPrice = prices[0];
            int max_profit = 0;

            for(int i=1; i<n; i++) {
                int p = prices[i];
                if( p < minPrice ) {
                    minPrice = p;
                } else if( p - minPrice > max_profit ) {
                    max_profit = p - minPrice;
                }
            }
            return max_profit;
        }
};