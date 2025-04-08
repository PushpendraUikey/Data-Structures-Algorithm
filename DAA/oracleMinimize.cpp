#include <bits/stdc++.h>
using namespace std;

// f(x) is convex.
// Convexity implies that f(x) is unimodal: there is exactly one global minimum, 
// and f(x) increases on either side of the minimum.
// The goal is to find an integer x that minimizes f(x) using the least number of oracle calls.


// Applying the ternary search here to compute the oracle
// Time complexity: O(log[3](N))
double minimize(int (*funct)(int)){
    double mini = -1000;   // change accordingly
    double maxi = 1000;

    double mid1 = mini + (maxi-mini)/3;
    double mid2 = maxi - (maxi-mini)/3;

    while(mid2-mid1 > 1){
        if(funct(mid1) < funct(mid2)){
            maxi = mid2;
        }else{
            mini = mid1;
        }
        mid1 = mini + (maxi-mini)/3;
        mid2 = maxi - (maxi-mini)/3;
    }

    if(funct(mid1) < funct(mid2)){
        return mid1;
    }else{
        return mid2;
    }
    
}

// The function is convex which has a minimum point guaranteed.
double minimizeII(double (*fn)(double), double (*fdashn)(double)){
    double mini = -1000;
    double maxi = 1000;
    
}

int function_(int x){
    return x*x*x*x-5*x*x+90*x;
}

int main(){
    std::cout << minimize(function_) << std::endl;
}