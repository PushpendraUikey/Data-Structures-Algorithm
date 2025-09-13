#include <bits/stdc++.h>
using namespace std;

// Cayley’s formula states that there are n^(n-2) labeled trees that contain n nodes.
// The nodes are labeled 1,2,...,n,and two trees are different if either their structure 
// orlabeling is different.

long long differentTrees(int n){
    int k = n-2;
    long long tree = 1;
    while(k>0){
        if(k&1) tree *= n;
        n *= n;
        k >>= 1;
    }
    return tree;
}