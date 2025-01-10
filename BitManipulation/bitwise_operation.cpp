#include<iostream>
using namespace std;

int main(){
    int a{17}, b{21};

    cout <<"a&b = " << (a&b) << endl;
    cout <<"a|b = " << (a|b) << endl;
    cout <<"a^b = " << (a^b) << endl;
    cout <<"~b = " << (~b) << endl;
    cout << "b<<1 = " << (b<<2) << endl;        // left shift
    cout << "a >> 1 = " << (a>>2) << endl;      // right shift
}
        // Statement after the continue are not executed, it lets the program to next iteration