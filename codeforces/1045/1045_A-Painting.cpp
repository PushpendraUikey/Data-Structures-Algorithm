#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;
    cin >> tt;
    while(tt--){
        int n, a, b;
        cin >> n >> a >> b;
        if(!( a%b==0 || b%a==0 ) ){
            cout << "No\n";
        }
    }
}