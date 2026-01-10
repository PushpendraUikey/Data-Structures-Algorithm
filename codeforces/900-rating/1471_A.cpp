#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Strange Partition
// https://codeforces.com/contest/1471/problem/A


ull n, x;
int arr[100005];
void solve() {
    cin >> n >> x;
    
    for(int i=0; i<n; i++) cin >> arr[i];

    ull mini = 0, maxi = 0;
    ull count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]%x==0) {
            maxi += arr[i]/x;
        }else{
            maxi += arr[i]/x + 1;
        }
        mini += arr[i];
        if(mini>x) {
            count += mini/x;
            mini %= x;
        }
    }

    if(mini%x==0) mini /= x;
    else {
        mini /= x;
        mini += 1;
    }

    mini += count;

    cout << mini << " " << maxi << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
