#include <bits/stdc++.h>
using namespace std;

void printBinary(int n){
    if(n == 0) return;
    printBinary(n/2);
    cout << n%2 << ' ';
}

int main(){
    int n; cout << "Give the number whose binary equivalent you want: "; cin >> n;
    cout << "Binary equivalent of " << n << " is :=== ";
    printBinary(n);
    cout << endl;
}