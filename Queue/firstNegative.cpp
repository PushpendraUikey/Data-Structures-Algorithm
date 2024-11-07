#include<bits/stdc++.h>
using namespace std;

/////// finding the first negative number in the window of k in an array

/*
K-sized window are solved using mostly queues or priority_queues. Sliding window technique can also
be used in it.*/

/*
Following problem needs queue and we are implementing it over indices
*/

vector<int> firstNegative(vector<int> &arr, int n, int k) {
	vector<int> ans;
	deque<int> dq;		// to store indices of negative values
	
	/// Process first window of size k
	for(int i=0; i<k; i++){
		if(arr[i]<0){
			dq.push_back(i);
		}
	}
	if(dq.size() > 0){
		ans.push_back(arr[dq.front()]);
	}else{
		ans.push_back(0);			// first k-sized window do not have negative value
	}
	// process remaining windows
	for(int i=k; i<n; i++){
		// removal
		if(!dq.empty() && i-dq.front() >= k){	/// window became more than size-k
			dq.pop_front();
		}
		// addition
		if(arr[i] < 0){
			dq.push_back(i);
		}

		if(dq.size()>0){
			ans.push_back(arr[dq.front()]);
		}else{
			ans.push_back(0);
		}

	}
	return ans;
}