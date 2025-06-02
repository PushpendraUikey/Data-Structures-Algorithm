#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t-->0){
        int n, k; cin >> n >> k;
        int arr[n/k][n/k];
        char val;

        for(int j=0; j<n; j++){
            for(int m = 0 ; m < n; m++){
                cin >> val;
                arr[j/k][m/k] = val;
            }
        }

        for(int i=0; i < n/k; i++){
            for(int j=0; j<n/k; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}
/*
4
4 4
0000
0000
0000
0000
6 3
000111
000111
000111
111000
111000
111000
6 2
001100
001100
111111
111111
110000
110000
8 1
11111111
11111111
11111111
11111111
11111111
11111111
11111111
11111111
*/