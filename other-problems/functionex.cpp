#include<iostream>
using namespace std;

bool isEven(int n){
    if(n&1) return false; //0       bitwise operation is being performed here.
    else return true; // 1
}
int factorial(int n){
    int fact{1};
    for(int i{1}; i<=n; i++){
        fact *= i;
    }
    return fact;
}
int nCr(int n, int r){
    int num = factorial(n);
    int den = factorial(r) * factorial(n-r);
    int fact = num/den;
    return fact;
}
int main(){
    int n, r;
    while(1){
        cin>>n >>r;
        if(n==0) break;
        cout << nCr(n,r) << endl;
    }
}