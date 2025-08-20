/*
Problem: Steady Electricity Paths in Grid

You are given a grid of size H x W. Each cell contains one of the following:
  - 'C' : Transformer
  - 'A' : Relay
  - '.' : Empty (can be replaced by either a Transformer or Relay)

Rules:
- The main power plant is connected to the top-left cell (1,1).
- The city's main power is connected to the bottom-right cell (H,W).
- Electricity can flow only to the right or down to adjacent cells.
- Electricity can flow only through relays or transformers.
- If a cell is '.', it can act as either a relay ('A') or a transformer ('C').
- Passing through a transformer flips the voltage (changes parity).
- The city requires steady voltage, i.e., the total number of transformers
  used along the path must be even.

Task:
Find the number of distinct paths from (1,1) to (H,W) such that the voltage
is steady at the destination.

Input:
- Integers H and W
- H lines of string of length W representing the grid.

Output:
- A single integer: number of valid paths with even number of transformers.

Constraints:
- 1 ≤ H, W ≤ 1000 (typical)
- Answer can be large, so use modulo if required.

Example:
Input:
2 2
A.
.C

Possible paths:
(1,1)→(1,2)→(2,2)  [A→Relay→C] → 1 transformer (odd) → invalid
(1,1)→(2,1)→(2,2)  [A→C] → 1 transformer (odd) → invalid

Output:
0
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7; // Use modulo to avoid overflow

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];

    // dp[i][j][p] = number of ways to reach (i,j) with parity p
    vector<vector<array<long long, 2>>> dp(H, vector<array<long long,2>>(W, {0,0}));

    // Initialize start cell
    if (grid[0][0] == 'A') dp[0][0][0] = 1;
    else if (grid[0][0] == 'C') dp[0][0][1] = 1;
    else if (grid[0][0] == '.') {
        dp[0][0][0] = 1; // as Relay
        dp[0][0][1] = 1; // as Transformer
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i==0 && j==0) continue;

            array<long long, 2> ways = {0,0};

            auto add_from = [&](int pi, int pj) {
                if (pi < 0 || pj < 0) return;
                for (int p = 0; p < 2; p++) {
                    long long val = dp[pi][pj][p];
                    if (!val) continue;
                    if (grid[i][j] == 'A') ways[p] = (ways[p] + val) % MOD;
                    else if (grid[i][j] == 'C') ways[p^1] = (ways[p^1] + val) % MOD;
                    else if (grid[i][j] == '.') {
                        ways[p]     = (ways[p] + val) % MOD;     // treat as Relay
                        ways[p^1]   = (ways[p^1] + val) % MOD;   // treat as Transformer
                    }
                }
            };

            add_from(i-1, j);
            add_from(i, j-1);

            dp[i][j] = ways;
        }
    }

    cout << dp[H-1][W-1][0] % MOD << "\n"; // steady voltage paths
    return 0;
}
