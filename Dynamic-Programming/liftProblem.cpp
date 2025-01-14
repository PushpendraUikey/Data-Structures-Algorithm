#include <bits/stdc++.h>
//  Using dynamic programming, it is often possible to change an iteration over
//  permutations into an iteration over subsets1. The benefit of this is that n!, the
//  number of permutations, is much larger than 2n, the number of subsets. For
//  example, if n=20, then n!=2.4*10^18 and 2^n=10^6


// Problem Statement
// There is an elevator with
//  maximum weight x, and n people with known weights who want to get from the
//  ground floor to the top floor. What is the minimum number of rides needed if the
//  people enter the elevator in an optimal order?

int __miniRide(std::vector<int>&_weights, int&_limit){
    int n = _weights.size();

//  rides(S) is the minimum number of rides for a subset S, and 
//  last(S) is the minimum weight of the last ride.
    std::pair<int, int> best[1<<n]; // contains(rides(S), last(S))

    best[0] = {1,0};
    for (int s = 1; s < (1<<n); s++) {
        // initial value: n+1 rides are needed
        best[s] = {n+1,0};
        for (int p = 0; p < n; p++) {
            if (s&(1<<p)) {
                auto option = best[s^(1<<p)];   // S which do not include p yet.
                if (option.second+_weights[p] <= _limit) {
                // add p to an existing ride
                option.second += _weights[p];
                } else {
                // reserve a new ride for p
                option.first++;
                option.second = _weights[p];
                }
                best[s] = std::min(best[s], option);
            }
        }
    }
}

// Note that the above loop guarantees that for any two subsets S1 and S2 such
//  that S1 S2, we process S1 before S2. Thus, the dynamic programming values
//  are calculated in the correct order.