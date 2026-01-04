#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// NIT Destroys the Universe
// https://codeforces.com/contest/1696/problem/B
int n;
int arr[200005];
void solve() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int oprn=0;
    int i=0; 
    while(i<n) {
        if(arr[i] == 0){
            i++;
            continue;
        }
        oprn++;
        while(i<n && arr[i] != 0){
            i++;
        }
    }

    cout << min(oprn, 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
