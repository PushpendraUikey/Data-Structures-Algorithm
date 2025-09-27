#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n; 
void solve() {
    cin >> n;
    if(n%3==0){
        cout << "Second\n";
    }else{
        cout << "First\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
