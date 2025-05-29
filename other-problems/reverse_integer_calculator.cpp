#include<iostream>
#include<math.h>

using namespace std;

int reverse(int n){
    int ans{0};
    while(n!=0){
        int digit = n % 10;
        ans = ans*10 + digit;
        n /=10;
    }
    return ans;
}
int simpleCalculator(char c, int a, int b){
    if(c =='+') return a+b;
    else if(c == '*') return a*b;
    else if(c == '%') return a%b;
    else if(c== '/') return a/b;
    else if(c == '-') return a-b;
    else return 0;
}

int main(){
    char op;
    int a, b;    
    cout << "Put an operation followed by two integers: ";
    cin >> op >> a >> b;

    cout << simpleCalculator(op, a, b) << endl;
}