#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int gcd(int a, int b){
            if(a==0) return b;
            if(b==0) return a;
            if(a<b) swap(a,b);

            while(b != 0){
                int temp = a%b;
                a = b;
                b = temp;
            }
            return a;
        }
};

int main(){
    int a, b;
    for(int i{0}; i<6; i++){
        cin >> a >> b;
        Solution sb;
        cout << "GCD of given numbers is: " << sb.gcd(a,b) << endl; 
    }

}
