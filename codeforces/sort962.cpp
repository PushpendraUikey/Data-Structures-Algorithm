#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;

    while(t-->0){
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        while( q-- > 0 ){
            int l, r; 
            cin >> l >> r;
            int oper = 0;
            l--;
            // r--;
            string t1 = a;
            string t2 = b;

            cout << t1 << endl;
            cout << t2 << endl;

            for(int i=l; i<r; i++){
                auto it = t2.find(t1[i], l);
                
                if(it == string::npos || it > r) {
                    oper++;
                }
            }

            cout << oper << endl;
        }
    }
}
/*
0
1
0
2
2
1
1
0
*/
// 1
// 5 3
// abcde
// edcba
// 1 5
// 1 4
// 3 3
