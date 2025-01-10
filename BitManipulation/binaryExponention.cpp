#include<bits/stdc++.h>

using namespace std;

int modularExponentiation(int x, int n, int m) {
	int ans = 1;
	if(n==0) return 1;

	while(n > 0){
        if(n&1){
		   //odd
		   ans = (1LL * (ans)  * (x)%m ) % m;
	    }
	    x = (1LL * (x)%m * (x)%m ) % m; 		// Here 1LL is multiplied to typecast
		n = n >> 1;	                            // one right shift pr 2 se divide hota hai
	}
	return ans;
}