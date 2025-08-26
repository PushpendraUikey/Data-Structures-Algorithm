/*
Problem: Max Items From Stalls

Problem Statement:

You are given an array `prices` of length `n`, where `prices[i]` represents the cost of the item 
at the i-th stall. It is guaranteed that `prices` is sorted in non-decreasing order.

You are also given `q` queries. Each query is described by two integers `(start, money)` meaning:
- You start buying from stall `start` (0-based index).
- You can buy at most one item per stall, moving only forward (towards higher indices).
- You have `money` units of currency to spend.

For each query, output the maximum number of items you can buy.

Input Format:
- First line: integer `n` — number of stalls.
- Second line: `n` integers — the array `prices`.
- Third line: integer `q` — number of queries.
- Next `q` lines: two integers each — `start money`.

Output Format:
- Print `q` integers, each representing the maximum number of items purchasable for that query.

Constraints:
- 1 ≤ n, q ≤ 100000
- 1 ≤ prices[i] ≤ 10^9
- 0 ≤ start < n
- 1 ≤ money ≤ 10^12

Example:
Input:
5
2 4 6 8 10
3
0 7
2 15
1 3

Output:
2
2
0
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxItemFromStall(vector<int>&prices, vector<pair<int, long long>>&queries){
    int n = prices.size();
    vector<int> ans;
    vector<long long> prefixsum(n,0);
    prefixsum[0] = prices[0];
    for(int i=1;i < n; i++) prefixsum[i] = prices[i]+prefixsum[i-1];

    for (auto [startidx, money] : queries) {
        // Assuming startidx is 1-based
        long long base = (startidx > 0 ? prefixsum[startidx-1] : 0);

        int lo = startidx, hi = n-1, best = startidx - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long long cost = prefixsum[mid] - base;
            if (cost <= money) {
                best = mid;
                lo = mid + 1; // try to take more items
            } else {
                hi = mid - 1;
            }
        }

        // number of items = (best - startidx + 1) if feasible, else 0
        ans.push_back(best >= startidx ? best - startidx + 1 : 0);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    int q;
    cin >> q;
    vector<pair<int,long long>> queries(q);
    for (int i = 0; i < q; i++) {
        int start;
        long long money;
        cin >> start >> money;
        queries[i] = {start, money};
    }

    vector<int> ans = maxItemFromStall(prices, queries);

    return 0;
}
