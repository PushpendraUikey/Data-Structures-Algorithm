#include<bits/stdc++.h>
using namespace std;

///// The following algorithm tells the occurance of any given number in the given sorted array 
///// in log(n);
//// This can be used to find the first and last occurance of an element in sorted array as well


int Search(vector<int> &arr,int s, int n, int x){
	int b = s;
	int e = n;
	int m = b+(e-b)/2;
	
	while(b<=e){
		if(arr[m] == x){
			return m;
		}else if(arr[m] > x){
			e = m-1;
		}else{
			b = m + 1;
		}
		m = b + (e-b)/2;
	}
	return -1;
}
int count(vector<int>& arr, int n, int x) {
	int s = Search(arr, 0, n-1, x);
	int t = s;
	if(s==-1) return 0;

	int b = Search( arr,0, s, x);
	while(s != b && b != -1){
		s=b;
		b = Search(arr,0, s, x);
	}

	int e = Search(arr, t+1, n-1, x);

	while(t != e && e != -1){
		t = e;
		e = Search(arr, e+1, n-1, x);
	}
	return t-s+1;
}