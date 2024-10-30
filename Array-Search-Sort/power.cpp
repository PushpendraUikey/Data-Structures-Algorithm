#include<bits/stdc++.h>
using namespace std;
#define max_size 10000
/*
Very optimized approach to find the power of some number which are very large.
*/

void Power(int, int);
void multiply(int[],int&,int);

int main(){
    int x,p; cin >> x >> p;
    Power(x,p);
}

void multiply(int power[],int& result_size, int x){
    int carry{0};
    for(int j{0}; j<result_size; j++){
        int product = power[j] * x + carry;
        power[j] = product%10;
        carry = product/10;
    }
    while(carry){
        power[result_size] = carry%10;
        carry /= 10;
        result_size++;
    }
}
void Power(int x, int p){
    int power[max_size] = {0};
    power[0]=x; int result_size=1;
    for(int i{1}; i<p; i++){
        multiply(power,result_size,x);
    }
    for(int j{result_size - 1}; j>=0; j--){
        cout<< power[j];
    }
    cout << endl;
}