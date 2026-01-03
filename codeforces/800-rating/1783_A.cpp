#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n;
int arr[51];

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    bool all_equal = true;
    for(int i=1; i<n; i++) {
        if(arr[i] != arr[i-1]) {
            all_equal = false;
            break;
        }
    }
    if(all_equal) {
        cout << "NO\n";
    }
    else{
        sort(arr, arr+n);
        if(arr[n-1] == arr[n-2]) {
            swap(arr[n-2], arr[0]);
        }
        cout << "YES\n";
        for(int i=n-1; i>=0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
