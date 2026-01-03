#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n;
ull arr[101];
int oprn=0;

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    oprn = 0;

    for(int i=0; i<n-1; i++) {
        if(arr[i]%2 == arr[i+1]%2) {
            oprn++;
        }
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
