#include<bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1071/
// The above problem is tried to be solve using some methamtical manipulations only.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    unsigned long long x,y;
    while(t-->0){
        cin >> y >> x;
        if (y > x){
            if(y%2 != 0){
                cout << (y-1)*(y-1) + x << "\n";
            }else{
                cout << y * y - x + 1 << "\n";
            }
        }else{
            if(x % 2 == 0){
                cout << (x-1)*(x-1) + y << "\n";
            }else{
                cout << x * x - y + 1 << "\n";
            }
        }
    }
}