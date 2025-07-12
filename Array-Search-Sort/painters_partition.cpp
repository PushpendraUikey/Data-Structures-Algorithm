#include <bits/stdc++.h>
using namespace std;

/*
Given an array/list of length ‘n’, where the array/list represents the boards 
and each element of the given array/list represents the length of each board. 
Some ‘k’ numbers of painters are available to paint these boards.
Consider that each unit of a board takes 1 unit of time to paint.
*/
bool isPossible(long long threshold, int k, vector<int>&boards){
	long long sum = 0;
	int cnt = 1;

	for(int i=0;i < (int)boards.size(); i++){
		if( boards[i] > threshold ) return false;

		if( boards[i] + sum > threshold ) {
			cnt++;
			sum = boards[i];
		}else{
			sum += boards[i];
		}
	}
	return cnt <= k;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
	long long total=0;
	for(const auto &e: boards){
		total+=e;
	}
	int ans = 0;
	long long low = 0, high = total;
	while(low <= high){
		long long mid = low + (high - low)/2;
		if(isPossible(mid, k, boards)){
			ans = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}

	return ans;
}