#include<iostream>
using namespace std;

int main(){
    cout << "Enter a positive number: ";
    int n; cin >> n;
    int sum{0}, pdt{1};
    while(n>0){
        sum += n%10;
        pdt *= n%10;
        n /= 10;
    }
    cout << "Difference of product and sum is: " << pdt - sum << endl;
}