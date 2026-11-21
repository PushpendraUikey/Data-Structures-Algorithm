#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalcost = 0;
        long long tc1=0;
        long long tc2=0;
        
        if(costBoth < cost1  && costBoth < cost2) {
            long long need = max(need1, need2);
            totalcost = need * (1LL * costBoth);
        }
        else if(costBoth > cost1 + cost2) {
            tc1 = (1LL*cost1) * (1LL*need1);
            tc2 = (1LL*cost2) * (1LL*need2);
            totalcost = tc1 + tc2;
        } 
        else if(costBoth < cost1 || costBoth < cost2) {
            if(cost1 > cost2) {
                tc1 = (1LL*need1) * (1LL*costBoth);
                if(need2 > need1){
                    tc2 = (need2-need1) * (1LL*cost2);
                }
            }
            else {
                tc2 = (1LL*need2) * (1LL*costBoth);
                if(need1 > need2) {
                    tc1 = (need1-need2) * (1LL*cost1);
                }
            }
            totalcost = tc1 + tc2;
        } 
        else {
            if(need1 < need2) {
                tc1 = (1LL*need1) * (1LL*costBoth);
                tc2 = (need2-need1) * (1LL*cost2);
            }else{
                tc1 = (1LL*need2) * (1LL*costBoth);
                tc2 = (need1-need2) * (1LL*cost1);
            }
            totalcost = tc1 + tc2;
        }
        return totalcost;
    }
};