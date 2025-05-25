#include <bits/stdc++.h>
using namespace std;

// Here is the recursive way to generate the permutation!
void __permutation(int&n, std::vector<int>& permutation, std::vector<std::vector<int> >& allpermutation,std::unordered_map<int, bool>&visited){
    if(permutation.size()==n){
        allpermutation.push_back(permutation);
        return;
    }
    for(int i=0; i<n; ++i){
        if(visited[i]) continue;
        permutation.push_back(i);
        visited[i] = true;
        __permutation(n, permutation, allpermutation, visited);
        // backTrack for another result
        visited[i] = false;
        permutation.pop_back();
    }
}

// here is the approach two using built in function!
// The total complexity is 𝑂(𝑛⋅𝑛!), where:
void __permutation2(int n, std::vector<std::vector<int>>& allpermutation){
    std::vector<int> permutation;
    for(int i=0; i<n; i++){
        permutation.push_back(i);
    }
    do {
        allpermutation.push_back(permutation);
    } while(std::next_permutation(permutation.begin(), permutation.end()));
}