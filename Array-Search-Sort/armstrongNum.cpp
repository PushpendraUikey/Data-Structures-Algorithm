#include<bits/stdc++.h>
using namespace std;

/*
An **Armstrong number** (or **narcissistic number**) is a number that is equal to the 
sum of its own digits each raised to the power of the number of digits. For example,
 \(153\) is an Armstrong number because \(1^3 + 5^3 + 3^3 = 153\).
*/
    string armstrongNumber(int n) {
        // code here
        string ans; int ansN;
        for(int i{1}; i<8; i++){
            for(int j{1}; j<8 ; j++){
                for(int k{1}; k<8 ; k++){
                    cout << "Currently i, j and k: " << i <<", " << j << " and " << k << endl;
                    ansN = pow(i,3) + pow(j,3) + pow(k,3) ;
                    if( ansN == n) {
                        ans = "true";
                        return ans;
                    }
                }
            }
        }
        ans = "false";
        return ans;
    }

    int main(){
        int n; cin >> n;
        cout << armstrongNumber(n) << endl;
    }