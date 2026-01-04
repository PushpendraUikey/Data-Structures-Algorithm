#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// AvtoBus
// https://codeforces.com/contest/1679/problem/A
ull n;
void solve() {
    cin >> n;
    if(n%2 != 0 || n<=3) {
        cout << -1 << "\n";
    }else{
        if(n%4 == 0) {
            if(n%3 == 0) {
                cout << n/6 << " " << n/4 << "\n";
            }else if((n-4)%3 == 0) {
                cout << (n-4)/6 + 1<< " " << n/4 << "\n";
            }else{
                cout << (n-8)/6 + 2 << " " << n/4 << "\n";
            }
        }else{
            if(n%6 == 0) {
                cout << n/6 << " " << (n-6)/4 + 1 << "\n";
            }else if((n-4)%6 == 0){
                cout << (n-4)/6 + 1 << " " << (n-6)/4 + 1 << "\n";
            }else{
                cout << (n-8)/6 + 2 << " " << (n-6)/4 + 1 << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
