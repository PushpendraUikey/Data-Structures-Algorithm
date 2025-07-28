#include <bits/stdc++.h>
using namespace std;

// You are given a string s consisting of n lowercase English letters. Each letter in the string can be
// shifted either to the left or the right alphabetically. For example, the letter 'g' can be changed to
// 'f' or 'h' in one shift. Assume that alphabets are circular, meaning 'z' shifts to 'a' on moving to the
// right, and 'a' shifts to 'z' on moving to the left. You are also given k, the maximum number of
// shifts you can use in total.
// Your task is to transform s into a palindrome using at most k shifts. Where among all possible
// palindromes that can be formed using at most k shifts, you have to find the lexicographical
// smallest one. If it is not possible to transform s into a palindrome return an empty string.

static inline int circDist(char from, char to) {
    int d = abs(from - to);
    return min(d, 26 - d);
}

string findSmallest(string s, int k) {
    int n = s.size();

    // 1) Make it a palindrome with minimal cost
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            // decide which way around the alphabet is cheaper
            int d1 = circDist(s[i], s[j]);
            k -= d1;
            if (k < 0) return "";           // impossible
            // which character is lexicographically smaller?
            char target = ( (s[i] < s[j]) ? s[i] : s[j] );
            s[i] = s[j] = target;
        }
    }

    // 2) With leftover k, push pairs toward 'a'
    for (int i = 0, j = n - 1; i < j && k > 0; ++i, --j) {
        if (s[i] == 'a') continue;
        int cost = 2 * circDist(s[i], 'a');
        if (cost <= k) {
            k -= cost;
            s[i] = s[j] = 'a';
        }
    }

    // 3) If odd length, maybe push the middle character to 'a'
    if (n % 2 == 1 && k > 0) {
        int mid = n / 2;
        int cost = circDist(s[mid], 'a');
        if (cost <= k) {
            s[mid] = 'a';
            // k -= cost;  // not needed after this
        }
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;

    string ans = findSmallest(s, k);
    if (ans.empty()) 
        cout << "-1\n";   // or whatever your "impossible" sentinel should be
    else
        cout << ans << "\n";

    return 0;
}
