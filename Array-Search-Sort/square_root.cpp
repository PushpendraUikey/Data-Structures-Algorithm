#include<bits/stdc++.h>
using namespace std;
/*
You are given an integer ‘A’. Your task is to find the greatest non-negative integer whose square 
is less than or equal to ‘A’.
Square of a number is the product of the number with itself. For e.g. square of 3 is 9.
*/ 
int squareRoot(int a)
{
	int low = 0; int high = a;
	int mid = low + (high-low)/2;
	while(low <= high){
		
		mid = low + (high - low)/2;
		if(mid*mid == a) return mid;
		else if(mid * mid > a){
			high = mid-1;
		}else{
			low = mid + 1;
		}
	}
    //======================== IMP
	return high;    // return low if you wanted the number to be smallest greater than equals the square.
}

int main(){
    int n; cout << "Give a number: "; cin >> n;
    cout << "ans: " << squareRoot(n) << endl;
}