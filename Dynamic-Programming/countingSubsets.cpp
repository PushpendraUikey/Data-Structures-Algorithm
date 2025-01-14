#include <bits/stdc++.h>

// _items has 1<<n values, corresponding to each subset
std::vector<int> __SubsetSumGenerator(std::vector<int>&_values, int n){
    int _sum[1<<n];
    for(int s=0; s<(1<<n); s++){
        _sum[s] = _values[s];
    }

    for(int k=0; k<n; ++k){
        for(int s=0; s<(1<<n); ++s){
            if(s&(1<<k)) _sum[s] += _sum[s^(1<<k)];
        }
    }
}