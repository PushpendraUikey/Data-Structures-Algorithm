#include<iostream>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t-->0){
        int n; cin >> n;
        for(int i{0}; i<n; i++){
            int k = 2;
            while(k-->0){
            for(int j{0}; j<n; j++){
                if( (i+j)%2 == 0){
                    cout << "##" ;
                }
                else{
                    cout << "..";
                }
            }
            if(k==0) continue;
            cout << endl;
            }
            cout << endl;
        }
    }
}