#include <bits/stdc++.h>
using namespace std;

long long power(long long n, long long k){
    // To calculate n^k;
    long long t = k;
    long long ans = 1;
    while(t){
        if(t&1) ans = n*ans;
        n = n*n;
        t >>= 1;
    }
    return ans;
}

long long repeatedSquaring(long long a, long long n){
    if(n==0) return 1;
    if(n==1) return a;
    if(n&1){
        return repeatedSquaring(a*a, n/2)*a;
    }else{
        return repeatedSquaring(a*a, n/2);
    }
}

long long repeatSquaring(long long a, long long n){
    if(n==0) return 1;
    if(n==1) return a;

    if(n&1){
        return repeatSquaring(a, n/2)*repeatedSquaring(a,n/2)*a;
    }else{
        return repeatSquaring(a, n/2)*repeatedSquaring(a,n/2);
    }
}


int main(int argc, char* argv[]){
    if(argc<3) return 0;
    long long n = std::stoi(argv[1]);
    long long k = std::stoi(argv[2]);
    std::cout << "Power of given numbers: "<< power(n, k) << std::endl;
}