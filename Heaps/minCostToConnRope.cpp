#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find the minimum cost to connect to rows, rows segments are given in array and cost of connecting 
two rows segments during the connecting comes to be proportional to the sum of segments
*/

int connectRopes(vector<int> &lengths, int n) {
	priority_queue<int, vector<int>, greater<int>> pq;

	for(auto& i: lengths){
		pq.push(i);
	}
	// int size = pq.size();
	int ans = 0;
	while(pq.size() > 1){
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		pq.push(a+b);
		ans+=(a+b);
	}
	return ans;
}