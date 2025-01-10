#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cout << "Enter the number to test: " ;
    int num; cin >> num;

    int count{0};
    while(num!=0){
        if(num&1) count++;
        num = num >> 1; // Right shift by one divides the number by one.
    }
    if(count == 1) cout << "It is a power of 2" << endl;
    else cout << "It is not the power of 2."<< endl;

}