#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Raspberries
// https://codeforces.com/contest/1883/problem/B

int n, k;
int arr[100005];
void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    if(k==4) {
        int div2=0;
        int rem4=0;
        for(int i=0; i<n; i++){
            if(arr[i]%4==0){
                div2 += 2;
                break;
            }
            else if(arr[i]%2==0){
                div2++;
            }else if(arr[i]%4==3){
                rem4++;
            }
        }

        if(div2 > 1){
            cout << 0 << '\n';
        }
        else if(div2 == 1){
            cout << 1 << '\n';
        }else{
            if(rem4>0){
                cout << 1 << '\n';
            }
            else{
                cout << 2 << '\n';
            }
        }
    }
    else {
        int minsteps = k;
        for(int i=0; i<n; i++){
            minsteps = min(minsteps, (k - arr[i]%k)%k);
        }

        cout << minsteps << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
