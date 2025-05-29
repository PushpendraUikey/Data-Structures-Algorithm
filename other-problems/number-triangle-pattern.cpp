#include<iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int i{1};
    int col{1};
    while(i<=n){
        int j{0};
        while(j<n-i){
            cout << "  ";
            j++;
        }
        j=1;
        while(j < i){
            cout << j <<" ";
            j++; 
        }
        while(j>0){
            cout << j << " ";
            j--;
        }
        cout << "\n";
        i++;
    }
}