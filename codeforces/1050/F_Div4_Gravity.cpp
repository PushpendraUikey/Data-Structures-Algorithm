#include <bits/stdc++.h>
using namespace std;

// Utility macros
#define all(x) (x).begin(), (x).end()

// Read multiple test cases
void solve() {
    int n; 
    cin >> n;

    // g[i] = the i-th sequence
    vector<vector<int>> sequences(n);

    // relevant[j] = indices of sequences that have an element at position j
    vector<vector<int>> relevant;
    int max_length = 0;

    for (int i = 0; i < n; i++) {
        int k; 
        cin >> k;
        sequences[i].resize(k);
        max_length = max(max_length, k);

        for (int j = 0; j < k; j++) {
            cin >> sequences[i][j];
            if ((int)relevant.size() == j) {
                relevant.push_back({});
            }
            relevant[j].push_back(i); // sequence i has a value at position j
        }
    }

    // lex_min[i] = sequence that provides the lexicographically minimal suffix starting at position i
    vector<int> lex_min(max_length);

    // rank[i] = rank of sequence i for tie-breaking when comparing suffixes
    vector<int> rank(n, -1);

    // Process from last column to first
    for (int pos = max_length - 1; pos >= 0; pos--) {
        vector<array<int, 3>> candidates;

        // Gather candidates: (value, rank at next position, sequence index)
        for (int seq : relevant[pos]) {
            candidates.push_back({sequences[seq][pos], rank[seq], seq});
        }

        // Sort candidates:
        // 1. By value at current position
        // 2. If tie, by rank (i.e., suffix from next position)
        sort(all(candidates));

        // The lexicographically best sequence for this position
        lex_min[pos] = candidates[0][2];

        // Assign new ranks for the sequences
        int current_rank = 0;
        for (auto &triple : candidates) {
            rank[triple[2]] = current_rank++;
        }
    }

    // Construct the answer
    vector<int> answer;
    while ((int)answer.size() < max_length) {
        int current_len = answer.size();
        auto &chosen_seq = sequences[lex_min[current_len]];
        
        // Append all remaining elements from this sequence starting at current_len
        for (int j = current_len; j < (int)chosen_seq.size(); j++) {
            answer.push_back(chosen_seq[j]);
        }
    }

    // Sanity check
    assert((int)answer.size() == max_length);

    // Output
    for (int x : answer) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
}
