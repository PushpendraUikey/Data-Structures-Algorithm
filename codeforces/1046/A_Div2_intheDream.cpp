#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if( a - 2*b > 2 || b - 2*a > 2){
            cout << "No\n";
        }else{
            c -= a; d -= b;
            if( c - 2*d > 2 || d - 2*c > 2){
                cout << "No\n";
            }else{
                cout << "Yes\n";
            }
        }
    }
}