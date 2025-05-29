#include<iostream>
using namespace std;

int main(){
	// Program for any n*n star patterns;
	int n; cin >> n;
	int i=1;
	char ch = 'A';
	while(i<=n){
		if(i%2==0){ 
			i++;
			continue;
		}
		for(int j{0}; j<n;j++){
			if(n-j>i){
				cout << " ";		// since space is not enough so it will show a beautyful equi triangle not a triangle by side
			}else {
				cout << "* ";
			}
		}
		cout << "\n";
		i++;
	}
}
