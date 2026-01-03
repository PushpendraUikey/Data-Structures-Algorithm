#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b, c;
void solve() {
    cin >> a >> b >> c;
    if(a > b + c){
        cout << "First\n";
    }
    else if( b > a + c ){
        cout << "Second\n";
    }
    else if( a + c%2 > b){
        cout << "First\n";
    }
    else {
        cout << "Second\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
