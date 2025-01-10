#include <bits/stdc++.h>

// There is a song concert going to happen in the city. The price of each ticket is equal to 
// the number obtained after reversing the bits of a given 32 bits unsigned integer ‘n’.

long reverseBits(long n) {
    long y = n;
    unsigned long x = 0;
    int i=31;
    while(i>0){
        int j = y&1;
        if(j) x += std::pow(2,i);
        i--;
        y = y>>1;
    }
    return x;
}