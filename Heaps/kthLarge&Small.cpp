#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find the kth largest and kth smallest element in an array.
*/
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// sort(arr.begin(), arr.end());
	// vector<int> ans;
	// ans.push_back(arr[k-1]);
	// ans.push_back(arr[n-k]);
	// return ans;
	priority_queue<int> pq;			/// we need this calculate kth smallest;
	priority_queue<int, vector<int>, greater<int>> minheap;		//// we need this to calculate kth largest
	for(int i=0; i<k;  i++){
		pq.push(arr[i]);
		minheap.push(arr[i]);
	}
	
	for(int i=k; i<n; i++){
		if(pq.top() > arr[i]){
			pq.pop();
			pq.push(arr[i]);
		}
		if(minheap.top() < arr[i]){
			minheap.pop();
			minheap.push(arr[i]);
		}
	}
	vector<int> ans;
	ans.push_back(pq.top());
	ans.push_back(minheap.top());
	return ans;
}