#include <bits/stdc++.h>
using namespace std;

// Majority Fingerprints. You are given a collection of n fingerprints. You are also told that more
//  than (n/2) of these are identical to each other. You are only given access to an equality test, which
//  takes two fingerprints and tells whether they are identical or not. Using this equality test, can you find
//  out the one with more than n2 copies in O(nlogn) time?

// here's the very efficient Boyre Moore algorithm ( the same I used in the Array-Search-Sort/Majority_Element.cpp )
// Assumption each fingerprint is assigned a number

int __MajorityFingerprint(std::vector<int>&fingerprints){
    int n = fingerprints.size();

    int cnt=0;
    int candidate = -1;

    for(int i=0; i<n; i++){
        if(cnt==0){
            candidate = fingerprints[i];
            cnt++;
        }else if( candidate == fingerprints[i]){
            cnt++;
        }else{
            cnt--;
        }
    }

    // checking the actual count
    cnt=0;
    for(int i=0; i<n; i++){
        if(fingerprints[i] == candidate) cnt++;
    }

    if(cnt > n/2) return candidate;
    else return -1;
}
