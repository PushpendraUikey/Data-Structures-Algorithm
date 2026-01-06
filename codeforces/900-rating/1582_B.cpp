#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Luntik and Subsequences
// https://codeforces.com/contest/1582/problem/B

int n;
int arr[61];
void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ones=0;
    int zeros = 0;
    for (int i=0; i<n;i++) {
        if(arr[i] == 1) ones++;
        else if(arr[i] == 0) zeros++;
    }

    if(ones == 0) {
        cout << "0\n";
    }else{
        ull ans = ones;
        if(zeros > 0) {
            ans = ans * (1ULL << zeros);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
