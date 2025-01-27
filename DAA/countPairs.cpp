#include <bits/stdc++.h>
using namespace std;

// You've given two sorted arrays and you've to count the pairs (a,b) such that a<b
// a belongs to array A and b belongs to array B.

int countpairs(std::vector<int>&a, std::vector<int>&b){
    int count = 0;
    int j=0;

    for(int i=0; i<a.size(); i++){
        while(a[i] >= b[j]) j++;
        count += (b.size()-j);  // number of elements in 'b' greater than a[i].
    }

    return count;
}