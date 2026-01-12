#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Helmets in Night Light
// https://codeforces.com/contest/1876/problem/A

int n, p;
pair<int, int> arr[100005];
void solve() {
    cin >> n >> p;
    for(int i=0; i<n; i++) cin >> arr[i].second;
    for(int i=0; i<n; i++) cin >> arr[i].first;

    sort(arr, arr+n);
    ll cost = p;
    int shared = 1;

    for(int i=0; i<n; i++){
        if(shared>=n){
            break;
        }

        if(arr[i].first > p){
            cost = cost + (1LL*(n-shared))*(1LL*p);
            break;
        }

        cost = cost + (1LL*arr[i].first) * (1LL*min(arr[i].second, n-shared));
        shared += arr[i].second;
    }

    cout << cost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
