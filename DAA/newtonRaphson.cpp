#include <bits/stdc++.h>
using namespace std;

double newton(double n){
    if(n < 0){
        throw std::invalid_argument("Square root of negative is not defined.");
    }
    if(n==0) return 0;
    double y = n/2;

    while(abs(y*y-n) > 1e-8){
        y = (y + n/y)/2.0;
    }
    return y;
}