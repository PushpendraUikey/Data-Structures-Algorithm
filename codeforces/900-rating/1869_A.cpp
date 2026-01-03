#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Make it Zero
// https://codeforces.com/contest/1869/problem/A

ull n;
ull arr[101];
void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    if(n%2==0){
        cout << "2\n";
        cout << "1 " << n << "\n";
        cout << "1 " << n << "\n";
    }else{
        cout << "4\n";
        cout << "1 " << n-1 << "\n";
        cout << "1 " << n-1 << "\n";
        cout << "2 " << n << "\n";
        cout << "2 " << n << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
