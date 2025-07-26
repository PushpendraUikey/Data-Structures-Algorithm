/*
Problem Statement:

You are given two arrays:
- `cake[]`: where `cake[i]` denotes the type of the i-th cake
- `happiness[]`: where `happiness[i]` denotes the happiness gained by eating the i-th cake

Rules:
- You start from index 0 and can move forward only.
- At each index, you can either:
    - Skip the cake, or
    - Eat the cake.

Bonus Rule:
- If you eat the current cake and **at least one** of the last two **eaten** cakes (not skipped) has the same type as the current one, then you gain **double** the happiness at that index.
- Otherwise, you gain normal happiness.

Task:
- Return the **maximum total happiness** you can collect by making optimal choices.

Constraints:
- 1 ≤ cake.length = happiness.length ≤ 1000
- Cake types are integers in a reasonable range (e.g., ≤ 100)

Approach:
- Dynamic Programming with state: (index, lastType1, lastType2)
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][101][101]; // dp[index][last1+1][last2+1]

int solve(int i, int last1, int last2, vector<int>& cake, vector<int>& happiness) {
    if (i == cake.size()) return 0;

    if (dp[i][last1+1][last2+1] != -1) return dp[i][last1+1][last2+1];

    // Option 1: Skip the cake
    int skip = solve(i+1, last1, last2, cake, happiness);

    // Option 2: Eat the cake
    int gain = happiness[i];
    if (cake[i] == last1 || cake[i] == last2)
        gain *= 2;
    int take = gain + solve(i+1, cake[i], last1, cake, happiness);

    return dp[i][last1+1][last2+1] = max(skip, take);
}

int maxHappiness(vector<int>& cake, vector<int>& happiness) {
    memset(dp, -1, sizeof(dp));
    return solve(0, -1, -1, cake, happiness);
}
