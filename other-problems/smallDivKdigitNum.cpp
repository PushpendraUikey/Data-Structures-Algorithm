#include <bits/stdc++.h>
using namespace std;

// we have to find out the smallest K digit number divisible by X,

class Solution {
  public:
    long long smallestKDigitNum(long long X, long long K) {
        long long n;
        n = pow(10,K-1);
        long long ans{-1};
        
        for(long long i = n; i <= n+X; i++){
            if(i % X == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X,K;
        
        cin>>X>>K;

        Solution ob;
        cout << ob.smallestKDigitNum(X,K) << endl;
    }
    return 0;
}