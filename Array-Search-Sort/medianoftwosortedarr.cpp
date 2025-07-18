#include <bits/stdc++.h>
using namespace std;

// Two sorted arrays of unequal lengths are given and you need to find the median of these elements
// We'll take the benefit of array being sorted and find the median using binary search approach

double findmedian(vector<int>&arra, vector<int>&arrb){
    int n = arra.size();
    int m = arrb.size();

    if(n > m) return findmedian(arrb, arra);

    int low = 0, high = n;
    int i1,i2;
    int lefta, righta, leftb, rightb;
    int realmid = (m+n+1)/2;
    
    while(low <= high){
        i1 = low + (high-low)/2;
        i2 = realmid - i1;
        lefta = i1 > 0 ? arra[i1-1] : INT_MIN;
        righta = i1 < n ? arra[i1] : INT_MAX;
        leftb = i2 > 0 ? arrb[i2-1] : INT_MIN;
        rightb = i2 < n ? arrb[i2] : INT_MAX;

        // Check for the correct partition
        if(lefta <= rightb && leftb <= righta){
            if( (m+n)%2==0 ){
                return (max(lefta, leftb) + min(righta, rightb)) / 2.0;
            }
            else{
                return max(lefta, leftb);
            }
        }
        else if(lefta > rightb){
            high = i1-1;
        }
        else{
            low = i1+1;
        }
    }

    return 0.0;
}