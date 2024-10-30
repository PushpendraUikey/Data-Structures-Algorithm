#include <bits/stdc++.h>
using namespace std;


class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    
	    if(n==1) return -1;
	    int secL = -1;
	    int firL = arr[0];
	    
	    for(int i{0}; i<n; i++){
	        
	        if(arr[i] >= firL) {
                if(arr[i] != firL) secL = firL;
                firL = arr[i];
                
	        }else if( secL < arr[i]){
                secL = arr[i];
                
            }
	    }
	    
	    return secL;
	    
	}
};


int main() {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
}
