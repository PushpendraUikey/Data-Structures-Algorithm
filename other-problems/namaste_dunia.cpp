#include<iostream>
using namespace std;

int main(){
	cout << "Namste Duniya\n";
	int a = 'a';
	cout << a << endl;
	unsigned int b = -23;
	cout << b << endl;

	char ch; cin >> ch;
	if(ch > 'a' && ch < 'z'){
		cout << "It is lowercase\n";
	}
	else if(ch > 'A' && ch < 'Z'){
		cout << "It is a uppercase\n";
	}
	else if(ch > '0' && ch < '9') 
		cout << "It is numberic\n";
}

