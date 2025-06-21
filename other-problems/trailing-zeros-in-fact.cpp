#include <bits/stdc++.h>
using namespace std;

//Power of p in n! = ⌊n / p⌋ + ⌊n / p²⌋ + ⌊n / p³⌋ + ... (until n / p^k < 1)

// Just need to find the power of 5 in the n!, since it's going to be lesser than 2's power
int trailingzeros(int n){
    if(n<=3) return 0;
    int p = log(n)/log(5);

    int zeros=0;
    do{
        zeros += (n/pow(5, p));
    }while(--p>0);

    return zeros;

}

// generalised approach to find the power of 'p' in n!
int countPowerOfPInFactorial(int n, int p) {
    int count = 0;
    while (n > 0) {
        n /= p;
        count += n;
    }
    return count;
}


int main(){
    int n; cin >> n;
    cout << "Trailing zeros in " << n << " is: " << trailingzeros(n) << endl;
}