#include <bits/stdc++.h>

// A binary indexed tree or a Fenwick tree can be seen as a dynamic variant
// of a prefix sum array. It supports two O(logn) time operations on an array:
// processing a range sum query and updating a value

// We'll have array representation of Bin Ind Tree, all arrays are one-index based
// tree[k] = sumq(k-p(k)+1,k), p(k) denotes largest power of two that divides 'k'.

// each position k contains the sum of values in a range of the original array
// whose length is p(k) and that ends at position k.

int __sum(std::vector<int>&arr, int a, int b){
    int sum = 0;
    for(int i=a; i<=b; ++i){
        sum += arr[i];
    }
    return sum;
}
void __buildBIT(std::vector<int>&arr, std::vector<int>&binItree){
    for(int k=1; k<=arr.size(); ++k){
        int pk = k & (-1*k);
        binItree[k] = __sum(arr, k-pk+1, k);

    }
}

// following implementation calculates sum in range [1, k] in binary index tree effectively
int __btreeSum(std::vector<int>&tree, int k){
    int s=0;
    while(k>=1){
        s+=tree[k];
        k -= k&(-1*k);
    }
    return s;
}

// following implementation calculates the sum in range [a,b] recursively
int __sumQueury(std::vector<int>&tree, int a, int b){
    if(a>1){
        int sum1 = __sumQueury(tree, 1, b);
        int sum2 = __sumQueury(tree, 1, a-1);
        return sum1-sum2;
    }
    int sum = 0;
    int i=0;
    while(b > 0){
        int p = std::pow(2, std::log2(b));
        i += p;
        sum += tree[i];
        b -= p;
    }
    return sum;
}

// following function increases the array value at poition k by x(+ve/-ve)
void __add(std::vector<int>&tree, int k, int x){
    while(k<=tree.size()){
        tree[k] += x;
        k += k&(-1*k);
    }
}