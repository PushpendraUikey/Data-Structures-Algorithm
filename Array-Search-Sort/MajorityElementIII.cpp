#include <bits/stdc++.h> 

//// all the elements whose occurrance is greater than equal to n/k, we are taking them in this problem

using namespace std;

vector<int> countTheNumber(vector<int> &arr, int n, int k) {
	vector<int> ans;
	map<int,int> mp;
	int m = n/k;
	for(int i=0; i<n; i++){
		mp[arr[i]]++;
	}
	for(auto it=mp.begin(); it != mp.end(); ++it){
		if(it->second >= m) ans.push_back(it->first);
	}
	return ans;
}