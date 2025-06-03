#include <iostream>
#include <vector>

// Following algorithm generates all the subsets of positive integers < n;

void subsets(int k, int& n, std::vector<int>&subset, std::vector<std::vector<int> >& ans){
    if(k==n){
        ans.push_back(subset);
    }
    subsets(k+1, n, subset, ans);
    subset.push_back(k);
    subsets(k+1, n, subset, ans);
    subset.pop_back();
}

// Here is another version(iterative) of subset generation of using the loop with same O(2^n * n) approach

//If the i-th bit of b is 1, element i is included in the subset.
//If the i-th bit of b is 0, element i is excluded.
void subsets1(int n){
    std::vector<std::vector<int> > ans;

    for(int b=0; b<(1<<n); ++b){
        std::vector<int> subset;
        for(int i=0; i<n; i++){
            if(b&(1<<i)) subset.push_back(i);   // if condition checks whether the ith bit is set or not set
        }
        ans.push_back(subset);
    }
}