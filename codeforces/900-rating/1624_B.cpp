#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Make AP
// https://codeforces.com/contest/1624/problem/B

int a, b, c;

void solve() {
    cin >> a >> b >> c;
    if( b >= a && b >= c ) {
        if(2*b == a + c) {
            cout << "YES\n";
        }else if( (2*b - c)>0 && (2*b - c) % a == 0 ) {
            cout << "YES\n";
        }else if((2*b-a)>0 && (2*b - a) % c == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }else 
    if( b < (a+c)/2){
        if(a%2 != c%2) cout << "NO\n";
        else if (((a+c)/2) % b == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }else{
        if(2*b-a > 0 && (2*b-a)%c==0){
            cout << "YES\n";
        }
        else if (2*b-c > 0 && (2*b-c) % a == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
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
