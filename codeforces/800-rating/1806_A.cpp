#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b > d) {
        cout << -1 << "\n";
        return;
    }

    int x_after_y = a + (d - b);
    if (x_after_y < c) {
        cout << -1 << "\n";
        return;
    }

    cout << (d - b) + (x_after_y-c) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
