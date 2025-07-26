/*
Problem Statement:

You're given an array `arr` of n (1 ≤ n ≤ 2 * 10^5) **distinct** positive integers.

You need to divide the elements into two **disjoint non-empty subsets A and B** such that:
- Every element of arr is in either A or B (i.e., A ∪ B = arr, A ∩ B = ∅)
- Both A and B are non-empty
- The **GCD of product of elements in A and product of elements in B is 1**, i.e.,
  GCD(product(A), product(B)) == 1

Count the number of such **ordered pairs** (A, B) satisfying the conditions.

Constraints:
- 1 ≤ arr[i] ≤ 1e5
- Elements in arr[] are distinct
- Answer modulo 1e9 + 7

Approach:
- Total number of valid ordered partitions: 2^n - 2
- Use Möbius function and inclusion-exclusion to count invalid pairs (where GCD(product A, product B) > 1)
- Subtract invalid count from total
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

vector<int> mu(MAX, 1), isPrime(MAX, 1), freq(MAX, 0), power2(MAX);

// Precompute Möbius function using Sieve
void mobius() {
    for (int i = 2; i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i; j < MAX; j += i) {
                isPrime[j] = 0;
                mu[j] *= -1;
            }
            for (int j = i * i; j < MAX; j += i * i)
                mu[j] = 0;
        }
    }
}

int countCoprimeSubsetPairs(vector<int>& arr) {
    int n = arr.size();
    mobius();

    // Count how many elements are divisible by each d
    for (int x : arr) freq[x]++;
    for (int i = MAX - 1; i >= 1; --i)
        for (int j = 2 * i; j < MAX; j += i)
            freq[i] += freq[j];

    // Precompute powers of 2 modulo MOD
    power2[0] = 1;
    for (int i = 1; i <= n; ++i)
        power2[i] = (2LL * power2[i - 1]) % MOD;

    // Total ordered disjoint non-empty partitions: 2^n - 2
    int total = (power2[n] - 2 + MOD) % MOD;

    // Count invalid partitions where gcd(product A, product B) > 1
    int bad = 0;
    for (int d = 2; d < MAX; ++d) {
        if (freq[d] < 2 || mu[d] == 0) continue;
        int subsetCnt = (power2[freq[d]] - 2 + MOD) % MOD;
        bad = (bad + 1LL * mu[d] * subsetCnt % MOD + MOD) % MOD;
    }

    return (total - bad + MOD) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    cout << countCoprimeSubsetPairs(arr) << "\n";
    return 0;
}
