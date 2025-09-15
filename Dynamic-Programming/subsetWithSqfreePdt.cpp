/*
Problem: Count Subsets with Square-Free Product

You are given an array A of integers, where each A[i] lies in the range [2, 30].
We want to count the number of subsets B of A such that the product of elements of B is:
    (1) Exactly equal to p1 * p2 * ... * pk, where each pi is a distinct prime
        (the target set of primes is given), OR
    (2) Any square-free product (i.e., the product of distinct primes, each prime used at most once).

Definitions:
- A number is square-free if it has no repeated prime factors. For example:
    - 6 = 2*3 is square-free
    - 12 = 2^2*3 is NOT square-free
- In this problem, numbers outside [2,30] do not appear, so the only primes are up to 29:
    {2,3,5,7,11,13,17,19,23,29} (10 primes total).

Constraints:
- 1 <= |A| <= 100 (reasonable size, since values are small and bitmask DP over 2^10 is fast)
- 2 <= A[i] <= 30
- Answer is required modulo 1e9+7

Approach:
- Map each valid square-free number v in [2,30] to a bitmask of its prime factors.
- Each element of A contributes either:
    - (a) nothing (skip it), or
    - (b) its mask (include it), if it doesn't overlap with already chosen primes.
- DP[mask] = number of ways to achieve prime set "mask".
- Iterate over all items and update DP with multiplicity (if there are multiple copies of v).
- For case (1): return dp[targetMask]
- For case (2): return sum of dp[mask] for all nonzero masks.

*/

#include <bits/stdc++.h>
using namespace std;
const int PRIMES[10] = {2,3,5,7,11,13,17,19,23,29};
const long long MOD = 1e9+7;

// mask for v (2..30). returns -1 if v is not square-free.
int maskOf(int v){
    int m = 0;
    for(int j=0;j<10;j++){
        int p = PRIMES[j];
        if(v%p==0){
            int c=0;
            while(v%p==0){ v/=p; c++; }
            if(c>1) return -1; // has square factor
            m |= (1<<j);
        }
    }
    if(v>1) return -1; // prime > 29 (not in our list) -> invalid
    return m;
}

// Count subsets whose product equals EXACT target set of distinct primes P
long long countExactTarget(const vector<int>& A, const vector<int>& targetPrimes){
    int cnt[31]={0};
    for(int x:A) cnt[x]++;

    vector<pair<int,int>> items; // (mask, multiplicity)
    for(int v=2; v<=30; v++){
        if(!cnt[v]) continue;
        int m = maskOf(v);
        if(m==-1) continue;
        items.push_back({m, cnt[v]});
    }

    const int FULL = 1<<10;
    vector<long long> dp(FULL, 0);
    dp[0]=1;

    for(auto [m, ways] : items){
        for(int mask=FULL-1; mask>=0; --mask){
            if((mask & m)==0){
                dp[mask|m] = (dp[mask|m] + dp[mask]*ways)%MOD;
            }
        }
    }

    int T=0;
    for(int p: targetPrimes){
        for(int j=0;j<10;j++) if(PRIMES[j]==p) T |= (1<<j);
    }
    return dp[T];
}

// Count subsets whose product is ANY square-free product
long long countAnySquareFreeProduct(const vector<int>& A){
    int cnt[31]={0};
    for(int x:A) cnt[x]++;

    vector<pair<int,int>> items;
    for(int v=2; v<=30; v++){
        if(!cnt[v]) continue;
        int m = maskOf(v);
        if(m==-1) continue;
        items.push_back({m, cnt[v]});
    }

    const int FULL = 1<<10;
    vector<long long> dp(FULL, 0);
    dp[0]=1;

    for(auto [m, ways] : items){
        for(int mask=FULL-1; mask>=0; --mask){
            if((mask & m)==0){
                dp[mask|m] = (dp[mask|m] + dp[mask]*ways)%MOD;
            }
        }
    }

    long long ans=0;
    for(int mask=1; mask<FULL; ++mask) ans = (ans + dp[mask])%MOD;
    return ans;
}

// Example usage
int main(){
    int n; cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];

    // Case 1: exact target product (e.g., 2*3*5)
    vector<int> target = {2,3,5};
    cout << "Exact target product count = " << countExactTarget(A, target) << "\n";

    // Case 2: any square-free product
    cout << "Any square-free product count = " << countAnySquareFreeProduct(A) << "\n";
    return 0;
}
