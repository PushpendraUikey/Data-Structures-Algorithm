#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n; 
int x;
void solve() {

    cin >> n >> x;
    vector<int> a(n);
    int maxGap=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i==0) maxGap = a[i];
        else {
            maxGap = max(maxGap, a[i]-a[i-1]);
        }
    }
    maxGap = max(maxGap, 2*(x-a[n-1]));

    cout << maxGap << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
