#include<bits/stdc++.h>
using namespace std;

/*
K'th largest sum in all possible subsequences sums
*/
// This is non-optimal solution using find all the sums and then sort them and return the kth largest elemennt

void getSum(vector<int>& arr, vector<int>&ans){
	int n = arr.size();
	for(int i=0; i<n;i++){
		int sum =0;
		for(int j=i; j<n; j++){
			sum+=arr[j];
			ans.push_back(sum);
		}
	}
}

int getKthLargest(vector<int> &arr, int k)
{
	vector<int> ans;
	getSum(arr, ans);
	
	sort(ans.begin(), ans.end());
	int n = ans.size();
	return ans[n-k];
}


/// Solution using heap
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>, greater<int>> ans;
	int p=0;
	int n = arr.size();

	for(int i=0; i<n;i++){
		int sum =0;
		for(int j=i; j<n; j++){
			sum+=arr[j];
			if(p++<k) ans.push(sum);
			else{
				if(ans.top()<sum){
					ans.pop();
					ans.push(sum);
				}
			}
		}
	}
	return ans.top();
}