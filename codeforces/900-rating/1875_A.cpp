#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull a, b, n;
ull arr[101];
void solve() {
    cin >> a >> b >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    ull total = b;
    for(int i=0; i<n; i++) {
        if(1+arr[i] > a) {
            total += a-1;
        }else{
            total += arr[i];
        }
    }
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
