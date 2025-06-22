#include<iostream>
#include<cmath>
using namespace std;

// Here's most efficient algorithm to calculate the power of 2
class Solution {
  public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n) {
        // Since only one bit is set in the power of 2
        return (n!=0) & (!(n&(n-1)));
    }
};

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