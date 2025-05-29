#include<iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int row{1}, col{0};
    while(row <= n){
        int i{1}, j{col};
        while(i <= n-j){
            cout << i << " ";
            i++;
        }
        while(j>0){
            cout <<"* ";
            j--;
        }
        i--;
        while(j<col){
            cout << "* ";
            j++;
        }
        while(i>0){
            cout << i << " ";
            i--;
        }
        cout << "\n";
        col++;
        row++;
    }
}