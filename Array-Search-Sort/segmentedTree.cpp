#include <bits/stdc++.h>

// We store a segment tree as an array of 2n elements where n is the size of the
// original array and a power of two. The tree nodes are stored from top to bottom:
// the parent of tree[k] is tree[k/2], and its children
// are tree[2k] and tree[2k+1].

std::vector<int> __buildSegmentTree(std::vector<int>&arr){
    int n = arr.size();
    std::vector<int> tree(2*n);
    for(int i=0; i<n ; ++i){
        tree[i+n] = arr[i];
    }
    for(int i=arr.size()-1; i>0; --i){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    return tree;
}

// Sum queury Range [a, b]
int __sum(std::vector<int>&tree, int a, int b){
    int n = tree.size()/2;
    a += n; b += n;
    int _sum = 0;
    while(a<=b){
        if(a%2==1) _sum+=tree[a++]; //if a is right child
        if(b%2==0) _sum+=tree[b--]; //if b is left child
        a /= 2; b /= 2;
    }
    return _sum;
}
// The function maintains a range that is initially [a+n,b+n]. Then, at each step,
//  the range is moved one level higher in the tree, and before that, the values of the
//  nodes that do not belong to the higher range are added to the sum.

// Updating the array, i.e. modifying the arr value at position k by x
void __add(std::vector<int>&tree, int k, int x){
    k += tree.size()/2;
    tree[k] += x;
    for(k/=2; k>=1; k/=2){
        tree[k] = tree[2*k]+tree[2*k+1];
    }
}


// Segment trees can support all range queries where it is possible to divide a range
//  into two parts, calculate the answer separately for both parts and then efficiently
//  combine the answers.