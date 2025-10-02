#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int minopr = INT_MAX;
int n, val;
void solve() {
    cin >> n;
    while(n--){
        cin >> val;
        if(abs(val) < minopr){
            minopr = abs(val);
        }
    }
    cout << minopr << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
