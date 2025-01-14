#include <bits/stdc++.h>

// We are given the prices of k
//  products over n days, and we want to buy each product exactly once. However,
//  we are allowed to buy atmost one product in a day. What is the minimum total
//  price?

// let total(S,d) denote the minimum total
// price for buying a subset S of products by day d

// total(S,d) = min(total(S,d-1),min{xbelongsS} (total(S\x,d-1)+price[x][d]))

int __optimalSolution(std::vector<std::vector<int>>&price, int k, int n){
    int total[1<<k][n]; //for dp table

    for(int x=0; x<k; ++x){
        total[1<<x][0] = price[x][0];   // day-0 set the price to price at 0th day if-only x is included.
    }

    for(int d=1; d<n; ++d){
        for(int s=0; s<1<<k; ++s){
            total[s][d] = total[s][d-1];
            for(int x=0; x<k; ++x){
                if(s&(1<<x)){   // if x is included in 's'.
                    total[s][d] = std::min(total[s][d], 
                                    total[s^(1<<x)][d-1]+price[x][d]);
                                    // we're considering subsets where 'x' is excluded.
                }
            }
        }
    }
}

// The time complexity of the algorithm is O(n*k*2^k).