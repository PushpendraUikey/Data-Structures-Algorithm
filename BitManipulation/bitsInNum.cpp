#include<iostream>
using namespace std;

int main(){
    unsigned int n; cin >> n;
    int count{0};
    for(int i{0}; i<32; i++){
    if(n&1){
        count++;
    }
    n = n>>1;
    }
    cout << "No's of 1's in " << n << " is : " << count << endl;
}