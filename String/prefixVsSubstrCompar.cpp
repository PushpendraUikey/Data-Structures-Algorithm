/*
Problem: Prefix vs Substring Comparison

You are given a string S of length N.

For each proper prefix of S (prefix length i, where 1 ≤ i ≤ N-1):
    - Compare this prefix with all substrings of S of the same length i.
    - For each substring comparison:
        * If prefix < substring (lexicographically), count as "less".
        * If prefix == substring, count as "equal".
        * If prefix > substring, count as "greater".
    - Record the triplet (lessCount, equalCount, greaterCount).

Output:
For each i (1 ≤ i ≤ N-1), output the triplet of counts.

------------------------------------------------------------
Example:

Input:
S = "abac"

Prefixes:
1. Prefix "a"
   Substrings length 1: "a", "b", "a", "c"
   Comparisons:
     "a" vs "a" → equal
     "a" vs "b" → less
     "a" vs "a" → equal
     "a" vs "c" → less
   => (less=2, equal=2, greater=0)

2. Prefix "ab"
   Substrings length 2: "ab","ba","ac"
   Comparisons:
     "ab" vs "ab" → equal
     "ab" vs "ba" → less
     "ab" vs "ac" → less
   => (less=2, equal=1, greater=0)

... and so on for prefix length 3.

------------------------------------------------------------
Constraints:
- 1 ≤ N ≤ 2000 for brute force solution.
- For larger N (up to 10^5), we need an optimized solution (Z-function).
*/

#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// Brute force solution: O(N^3)
// ------------------------------------------------------------
vector<tuple<int,int,int>> bruteForce(const string& s) {
    int n = s.size();
    vector<tuple<int,int,int>> result;

    for (int len = 1; len < n; len++) {
        string prefix = s.substr(0, len);
        int lessCnt = 0, equalCnt = 0, greaterCnt = 0;

        for (int i = 0; i + len <= n; i++) {
            string sub = s.substr(i, len);
            if (prefix < sub) lessCnt++;
            else if (prefix == sub) equalCnt++;
            else greaterCnt++;
        }

        result.push_back({lessCnt, equalCnt, greaterCnt});
    }

    return result;
}

// ------------------------------------------------------------
// Optimized solution using Z-function: O(N^2)
// ------------------------------------------------------------

// Compute Z-function: z[i] = length of longest common prefix of s[i:] and s[0:]
vector<int> zFunction(const string& str) {
    int n = str.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<tuple<int,int,int>> optimized(const string& s) {
    int n = s.size();
    vector<tuple<int,int,int>> result;

    for (int len = 1; len < n; len++) {
        string prefix = s.substr(0, len);
        int lessCnt = 0, equalCnt = 0, greaterCnt = 0;

        // Build new string = prefix + '$' + s
        string combined = prefix + '$' + s;
        vector<int> z = zFunction(combined);

        for (int i = 0; i + len <= n; i++) {
            int pos = len + 1 + i; // starting index of substring in combined
            int matchLen = z[pos];
            if (matchLen >= len) {
                equalCnt++;
            } else {
                if (s[i + matchLen] < prefix[matchLen]) greaterCnt++;
                else lessCnt++;
            }
        }
        result.push_back({lessCnt, equalCnt, greaterCnt});
    }
    return result;
}

// ------------------------------------------------------------
int main() {
    string s;
    cin >> s;

    // Brute force (use when N <= 2000)
    auto brute = bruteForce(s);
    cout << "Brute Force Results:\n";
    for (auto [l, e, g] : brute) {
        cout << l << " " << e << " " << g << "\n";
    }

    // Optimized
    auto opt = optimized(s);
    cout << "Optimized Results:\n";
    for (auto [l, e, g] : opt) {
        cout << l << " " << e << " " << g << "\n";
    }
    return 0;
}


// Here's the most optimized solution to the problem CHATGPT!!!

// ---------- Suffix Array (doubling) ----------
vector<int> build_sa(const string& s) {
    int n = (int)s.size();
    vector<int> sa(n), rnk(n), tmp(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; i++) rnk[i] = s[i];
    for (int k = 1;; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (rnk[a] != rnk[b]) return rnk[a] < rnk[b];
            int ra = (a + k < n ? rnk[a + k] : -1);
            int rb = (b + k < n ? rnk[b + k] : -1);
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        for (int i = 0; i < n; i++) rnk[i] = tmp[i];
        if (rnk[sa.back()] == n - 1) break;
    }
    return sa;
}

// ---------- Kasai LCP ----------
vector<int> build_lcp(const string& s, const vector<int>& sa) {
    int n = (int)s.size();
    vector<int> rnk(n), lcp(n);
    for (int i = 0; i < n; i++) rnk[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++) {
        int ri = rnk[i];
        if (ri == 0) { k = 0; continue; }
        int j = sa[ri - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[ri] = k; // LCP between sa[ri-1] and sa[ri]
        if (k) k--;
    }
    return lcp;
}

// ---------- RMQ (sparse table) for min over LCP ----------
struct RMQ {
    int n, K;
    vector<vector<int>> st;
    vector<int> lg;
    RMQ() {}
    RMQ(const vector<int>& v) { build(v); }
    void build(const vector<int>& v) {
        n = (int)v.size();
        K = 32 - __builtin_clz(n ? n : 1);
        st.assign(K, vector<int>(n));
        st[0] = v;
        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);
            }
        }
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
    }
    // min on [l, r], inclusive
    int query(int l, int r) const {
        if (l > r) return INT_MAX;
        int k = lg[r - l + 1];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

// LCP between suffixes at SA ranks a and b (a<b): min LCP on (a+1..b)
int lcp_between(const RMQ& rmq, int a, int b) {
    if (a == b) return INT_MAX;
    if (a > b) swap(a, b);
    return rmq.query(a + 1, b);
}

// ---------- Fenwick (BIT) over SA positions ----------
struct BIT {
    int n; vector<int> bit;
    BIT(int n=0): n(n), bit(n+1,0) {}
    void add(int idx, int val) { // idx in [0..n-1]
        for (int i = idx + 1; i <= n; i += i & -i) bit[i] += val;
    }
    int sumPrefix(int idx) const { // sum [0..idx]
        int s = 0;
        for (int i = idx + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    int rangeSum(int l, int r) const {
        if (l > r) return 0;
        return sumPrefix(r) - (l ? sumPrefix(l - 1) : 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    if (!(cin >> S)) return 0;
    int N = (int)S.size();
    if (N <= 1) return 0;

    // Build SA, LCP, rank
    vector<int> SA = build_sa(S);
    vector<int> LCP = build_lcp(S, SA);
    vector<int> rank_(N);
    for (int i = 0; i < N; i++) rank_[SA[i]] = i;

    RMQ rmq(LCP);
    int r0 = rank_[0]; // SA position of the full string (prefix starting at 0)

    // We’ll process i from N-1 down to 1, activating starts j ≤ N - i.
    BIT bit(N);
    vector<int> active(N, 0);
    int maxStartActive = -1;

    // Helper to expand around r0 to get [L,R] where LCP with suffix 0 ≥ len
    auto get_interval = [&](int len) -> pair<int,int> {
        // Binary search left boundary L
        int L = r0, lo = 0, hi = r0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int mnlcp = (mid == r0) ? INT_MAX : lcp_between(rmq, mid, r0);
            if (mnlcp >= len) { L = mid; hi = mid - 1; }
            else lo = mid + 1;
        }
        // Binary search right boundary R
        int R = r0; lo = r0; hi = N - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int mnlcp = (mid == r0) ? INT_MAX : lcp_between(rmq, r0, mid);
            if (mnlcp >= len) { R = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return {L, R};
    };

    vector<tuple<int,int,int>> ans(N); // store at index i: for prefix length i
    for (int len = N - 1; len >= 1; --len) {
        // Activate all starts j ≤ N - len
        while (maxStartActive + 1 <= N - len) {
            int j = ++maxStartActive;
            int pos = rank_[j];
            if (!active[pos]) { active[pos] = 1; bit.add(pos, 1); }
        }

        auto [L, R] = get_interval(len);
        int equalCnt   = bit.rangeSum(L, R);
        int lessCnt    = bit.rangeSum(0, L - 1);
        int greaterCnt = bit.rangeSum(R + 1, N - 1);

        ans[len] = {lessCnt, equalCnt, greaterCnt};
    }

    // Output for i = 1..N-1
    for (int i = 1; i <= N - 1; i++) {
        auto [l, e, g] = ans[i];
        cout << l << " " << e << " " << g << "\n";
    }
    return 0;
}