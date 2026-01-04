#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Array Cloning Technique
// https://codeforces.com/contest/1665/problem/B

int n;
int arr[100005];
void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int count = 1;
    int max_freq = 1;
    int max_elem = arr[0];
    for (int i=1; i<n; i++) {
        if(arr[i] == arr[i-1]) {
            count++;
        } else {
            if(count > max_freq ) {
                max_freq = count;
                max_elem = arr[i-1];
            }
            count = 1;
        }
    }

    if(count > max_freq) {
        max_freq = count;
        max_elem = arr[n-1];
    }
    
    int oprn = 0;
    while(max_freq < n) {
        oprn++; // for cloning
        oprn += min(max_freq, n - max_freq);    // For swaps
        max_freq*=2;    // After cloning max_freq doubles
    }

    cout << oprn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
