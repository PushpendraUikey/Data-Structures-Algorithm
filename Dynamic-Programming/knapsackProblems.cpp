#include <bits/stdc++.h>
using namespace std;

//The term knapsack refers to problems where a set of objects is given, and
//  subsets with some properties have to be found.

// Given a list of weights
//  [w1,w2,...,wn], determine all sums that can be constructed using the weights

//  possible(x,k) = possible(x wk,k 1) or possible(x,k 1)
void __allsums(std::vector<int>&_weights, std::vector<int>&_ans){
    int W=0;
    for(auto& w:_weights){
        W += w;
    }
    int n = _weights.size();
    std::vector<std::vector<bool>> _possible(W+1, std::vector<bool>(n+1, 0));

    _possible[0][0] = true;

    for(int k=1; k<=n; ++k){
        for(int x=0; x<=W; ++x){
            if(x-_weights[k] >= 0) _possible[x][k] = _possible[x][k]||_possible[x-_weights[k]][k-1];
            _possible[x][k] = _possible[x][k] || _possible[x][k-1];
        }
    }

    // now iterating over the weights and finding the true's will give the sums that can be formed using 
    // the give values.
}


// Here's a bit efficient approach to solve the above problem
void __allsums2(std::vector<int>&_weights, std::vector<int>&_ans){
    int W=0;
    for(auto& c:_weights){
        W+=c;
    }
    std::vector<bool> _possible(W+1, false);
    int n = _weights.size();
    _possible[0] = true;
    _possible[W] = true;
    for(int k=1; k<=n; ++k){
        for(int x=W; x>=0; --x){
            if(_possible[x] && x-_weights[k]>=0) _possible[x-_weights[k]] = true;  
        }
        // Here's the alternative!
        // for(int x=0; x<=W; ++x){
        //     if(_possible[x] && x+_weights[k] <= W) _possible[x+_weights[k]] = true;
        // }
    }
}