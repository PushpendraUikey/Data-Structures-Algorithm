#include <bits/stdc++.h>
using namespace std;

// Every male member (M) gives birth to a male child first and then a female child, 
// whereas every female (F) member gives birth to a female child first and then to a male child. 
// Analyse this pattern and find out what will be the Kth child in his Nth generation.

string kthChildNthGeneration(int n, long long int k)
{
	bool isMale = true;

	while(k>1){
		if(k%2==0){
			isMale = !isMale;
		}
		k = (k+1)/2;
	}
	
	return isMale? "Male":"Female";
}