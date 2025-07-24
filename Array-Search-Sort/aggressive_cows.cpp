#include <bits/stdc++.h>
using namespace std;

/*
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum 
distance between any two of them is the maximum possible.
Print the maximum possible minimum distance.
Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
*/

bool isPossible(int gap, int k, vector<int>&stalls){
	int lastpos = 0;
	int cnt = 1;
	for(int i=1; i<(int)stalls.size(); i++){
		if(stalls[i] - stalls[lastpos] >= gap){
			lastpos = i;
			cnt++;
		}
	}
	return cnt >= k;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
	int mini = INT_MAX;
	int maxi = INT_MIN;
	for(auto& v: stalls){
		mini = min(v, mini);
		maxi = max(v, maxi);
	}
	sort(stalls.begin(), stalls.end());

	int low = 0, high = maxi - mini;
	int gap = 0;
	while(low <= high){
		gap = low + (high-low)/2;
		if(isPossible(gap, k, stalls)){
			low = gap + 1;
		}else{
			high = gap - 1;
		}
	}

	return high;
}
// mid is recalculated inside the loop so it might not be the best answer
// also low is the first failed number and high is the last passed number hence 
// returning high gives correct answer.