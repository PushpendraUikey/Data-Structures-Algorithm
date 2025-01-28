#include <bits/stdc++.h>

// original array is the prefix sum array of difference array.
std::vector<int> __diffArr(std::vector<int>&arr){
    std::vector<int> diffarr;
    diffarr.push_back(arr[0]);
    for(int i=1; i<arr.size(); ++i){
        diffarr.push_back((arr[i]-arr[i-1]));
    }
    return diffarr;
}

// diffarray's are quite useful when we have to update the value's in a range and not at a particular index.
// suppose we've to increase the values of arr in range [a,b] by x, so it can be efficiently done
void __increment(std::vector<int>&diffarr, int a, int b, int x){
    diffarr[a] += x;
    if(b+1<diffarr.size()) diffarr[b+1] -= x;
}
// Similar thing can be done if we have to decrement the elements of a range!