#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while(tt--){
        ll k, x;
        cin >> k >> x;

        while(k--){
            if(x > 10 && (x-1)%3 == 0 && ((x-1)/3)%2 != 0){
                x = (x-1)/3;
            }else{
                x *= 2;
            }
        }
        cout << x << "\n";
    }
}