#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n; cin >> n;
    int i{0},dec{0};
    while(n !=0 ){
        int bit = n % 10;
        dec += pow(2,i) * bit;
        n /= 10;
        i++;
    }
    cout << "Decimal representation of given binary is " << dec << endl;
}