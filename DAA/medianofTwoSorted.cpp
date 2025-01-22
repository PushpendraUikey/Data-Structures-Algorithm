#include <bits/stdc++.h>
#define ll long long
using namespace std;

// We can calculate the median of two sorted arrays of length m, n using binary search efficiently
// if m+n is even then average of middle elements and if it is odd then mid element after merging 
// in sorted form but we don't actually have to merge.

// Time complexity: O(log[min(n,m)])

// Small assumption I'd like to make is size of vector 'a' is less than equals to vector 'b'
int median(std::vector<int>&a, std::vector<int>&b){

    if(a.size() > b.size()){
        return median(b, a);
    }

    int n = a.size(), m = b.size();
    int s=0, e=n;
    bool isOdd = false;
    if((m+n)%2==0) isOdd = false;
    else isOdd = true;
    while(s<=e){
        int i = s + (e-s)/2;
        int j = (m+n+1)/2 - i;

        // out-of-index bounding
        int aleft = (i==0) ? INT_MIN : a[i-1];
        int aright = (i==n) ? INT_MAX : a[i];
        int bleft = (j==0) ? INT_MIN : b[j-1];
        int bright = (j==m) ? INT_MAX : b[j];


        // validity check for median candidature[ it can be shown only suitable index will hold this ]
        if(aleft <= bright && bleft <= aright){
            if(isOdd){
                return std::max(a[i-1], b[j-1]);
            }else{
                return (std::max(a[i-1], b[j-1]) + std::min(a[i], b[j]))/2;
            }
        }else if(aleft > bright){
            // moving partition to left
            e = i - 1;
        }else{
            // moving partition to right
            s = i + 1;
        }
    }
    return -1; // although this won't be reached!
}
