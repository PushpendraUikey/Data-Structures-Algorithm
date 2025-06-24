#include <bits/stdc++.h>
using namespace std;

// decimal equivalent of gray number to decimal equivalent of binary number conversion.
int grayToBinary(int n) {

    int num = 0;
    int last = 0;
    for(int i=31; i>=0; i--){
        last ^= ((n&(1<<i))>>i);    // we just need that bit at the most significant position
        num |= last * (1<<i);
    }
    return num;
}

int main(){
    int in; cout << "Give the number: ";
    cin >> in;
    cout << grayToBinary(in) << endl;
}
