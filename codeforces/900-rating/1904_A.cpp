#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int a, b;
int xk, yk;
int xq, yq;

set<pair<int,int>> pt1, pt2;
void solve() {
    cin >> a >> b;
    cin >> xk >> yk;
    cin >> xq >> yq;
    pt1.insert({xk + a, yk + b});
    pt1.insert({xk + a, yk - b});
    pt1.insert({xk - a, yk + b});
    pt1.insert({xk - a, yk - b});
    pt1.insert({xk + b, yk + a});
    pt1.insert({xk + b, yk - a});
    pt1.insert({xk - b, yk + a});
    pt1.insert({xk - b, yk - a});

    pt2.insert({xq + a, yq + b});
    pt2.insert({xq + a, yq - b});
    pt2.insert({xq - a, yq + b});
    pt2.insert({xq - a, yq - b});
    pt2.insert({xq + b, yq + a});
    pt2.insert({xq + b, yq - a});
    pt2.insert({xq - b, yq + a});
    pt2.insert({xq - b, yq - a});

    int commonpts = 0;
    for (auto p : pt1) {
        if (pt2.count(p)) commonpts++;
    }
    cout << commonpts << "\n";
    pt1.clear();
    pt2.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
