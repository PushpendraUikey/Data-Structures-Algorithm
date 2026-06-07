#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Olya and Game with Arrays
// https://codeforces.com/contest/1859/problem/B

int n;
ull arr[50005];
ull miniarr[50005];
int m;
void solve() {
    cin >> n;
    
    ull sum = 0;
    int minifirst = INT_MAX;
    int minisecond = INT_MAX;
    int globalmin = INT_MAX;
    for(int i=0; i<n; i++){
        cin >> m;
        minifirst = INT_MAX;
        minisecond = INT_MAX;
        for(int j=0; j<m; j++) {
            cin >> arr[j];
            if(arr[j] < minifirst){
                minisecond = minifirst;
                minifirst = arr[j];
            }else if(arr[j] < minisecond){
                minisecond = arr[j];
            }
        }
        miniarr[i] = minisecond;
        globalmin = min(globalmin, minifirst);
    }

    sort(miniarr, miniarr+n);
    for(int i=1; i<n; i++){
        sum += miniarr[i];
    }
    sum = sum + globalmin;
    
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
