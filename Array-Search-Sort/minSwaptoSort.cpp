#include<bits/stdc++.h>
using namespace std;

// Not written by me!
// Distinct elements ranging from 0 to n-1
int minSwaps(vector<int> &arr)
{
	int n = arr.size();
	vector<pair<int, int>> v(n);
	for(int i=0; i<n; i++){
		v[i] = {arr[i], i};
	}

	sort(v.begin(), v.end());
	int cnt=0;
	for(int i=0; i<n; i++){
		if(v[i].second==i){
			continue;
		}else{
			swap(v[i], v[v[i].second]);
			cnt++;
			i--;
		}
	}
	
	return cnt;
}