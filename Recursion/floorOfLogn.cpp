#include <bits/stdc++.h>
using namespace std;

int floorLogn(int n){
    if(n==1) return 0;

    return 1 + floorLogn(n/2);
}

int main(){
    int n; cout << "Give the number whose floor of log you need: "; cin >> n;

    cout << "Floor of logn is: " << floorLogn(n) << endl;
}