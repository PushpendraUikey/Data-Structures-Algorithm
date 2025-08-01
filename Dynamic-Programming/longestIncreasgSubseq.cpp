#include <bits/stdc++.h>
using namespace std;

// Here is the idea
// To calculate a value of length(k), we should find a position i<k for which
// array[i]<array[k] and length(i) is as large as possible. Then we know that
// length(k)=length(i)+1, because this is an optimal way to add array[k] to a
// subsequence.

class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(vector<int>& arr) {
        vector<int> length(arr.size());
        for(int i=0; i<arr.size(); i++){
            length[i] = 1;
            for(int j=0; j<i; j++){
                if(arr[j] < arr[i]){
                    length[i] = max(length[i], length[j]+1);// finding the max Longest subseq at 'i' from prev built subsequences
                }
            }
        }
        
        int maxi=1;
        for(auto& e: length){
            if(e>maxi) maxi = e;
        }
        
        return maxi;
    }
};

// Credit: GfG
// Longest Increasing Subsequence using Memoization DP recursion
/* A Naive C++ recursive implementation
of LIS problem */
#include <iostream>
using namespace std;

/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
	We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
	an element before arr[n-1] max_ref is
	used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
	/* Base case */
	if (n == 1)
		return 1;

	// 'max_ending_here' is length of LIS
	// ending with arr[n-1]
	int res, max_ending_here = 1;

	/* Recursively get all LIS ending with arr[0],
	arr[1] ... arr[n-2]. If arr[i-1] is smaller
	than arr[n-1], and max ending with arr[n-1]
	needs to be updated, then update it */
	for (int i = 1; i < n; i++) {
		res = _lis(arr, i, max_ref);
		if (arr[i - 1] < arr[n - 1]
			&& res + 1 > max_ending_here)
			max_ending_here = res + 1;
	}

	// Compare max_ending_here with the overall
	// max. And update the overall max if needed
	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;

	// Return length of LIS ending with arr[n-1]
	return max_ending_here;
}

// The wrapper function for _lis()
int lis(int arr[], int n)
{
	// The max variable holds the result
	int max = 1;

	// The function _lis() stores its result in max
	_lis(arr, n, &max);

	// returns max
	return max;
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout <<"Length of lis is "<< lis(arr, n);
	return 0;
}

/* A Naive C++ recursive implementation
of LIS problem */

/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
	We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
	an element before arr[n-1] max_ref is
	used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
	/* Base case */
	if (n == 1)
		return 1;

	// 'max_ending_here' is length of LIS
	// ending with arr[n-1]
	int res, max_ending_here = 1;

	/* Recursively get all LIS ending with arr[0],
	arr[1] ... arr[n-2]. If arr[i-1] is smaller
	than arr[n-1], and max ending with arr[n-1]
	needs to be updated, then update it */
	for (int i = 1; i < n; i++) {
		res = _lis(arr, i, max_ref);
		if (arr[i - 1] < arr[n - 1]
			&& res + 1 > max_ending_here)
			max_ending_here = res + 1;
	}

	// Compare max_ending_here with the overall
	// max. And update the overall max if needed
	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;

	// Return length of LIS ending with arr[n-1]
	return max_ending_here;
}

// The wrapper function for _lis()
int lis(int arr[], int n)
{
	// The max variable holds the result
	int max = 1;

	// The function _lis() stores its result in max
	_lis(arr, n, &max);

	// returns max
	return max;
}
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout <<"Length of lis is "<< lis(arr, n);
	return 0;
}


// Longest Increasing Subsequence in O(nlogn): Binary Search Used here
int ceilIdx(int*tail, int l, int r, int num){
    while(l < r){
        int m = l + (r-l)/2;
        if(tail[m] >= num){
            r = m;
        }else{
            l = m+1;
        }
    }
    return r;
}
int longestIncreasingSubsequence_logn(const vector<int>&arr){
    int n = arr.size();
    int len = 1;
    int tail[n];
    tail[0] = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] > arr[len-1]){
            tail[len] = arr[i]; len++;
        }else{
            int c = ceilIdx(tail, 0, len-1, arr[i]);    // since tail is sorted ceil exists
            tail[c] = arr[i];
        }
    }
}

// $$$$$$$$$$$$$$$$$ Variation of LIS $$$$$$$$$$$$$$$$$

// 1) Minimum deletions to make an array sorted!
// Approach is simple: array.lenght - LIS;

// 2) Maximum Sum Increasing Subsequence
// Similar to LIS algorithm just the DP array is going to hold the Maximum Increasing Sum till the current idx

// 3) Maximum length Bitonic Subsequence: Subsequence which first increases then decreases
// Let LIS be the longest increasing subsequence of the array
// Similarly make LDS, longest decreasing subsequence from the given element, Similar approach but just
// Traverse from the right end of the array!

// 4) Building Bridges, given a set of pairs of value <first,second> which denotes there's a bridge from 
// first to second. if These numbers are placed in sorted order in two rows then maximum number of bridges
// we can form without crossing each other?  O(nlogn)
// Sort the array in increasing order of first value and if first of two pairs are equal then according to
// second value, Find LIS using second values of array that is the number of bridges we can form

// 5) Longest Chain of Pairs, let (a, b) (c, d) are in chain then b < c.
// IMPORTANT: This is Greedy problem of selecting maximum number of jobs can be done in a machine given
// their start and end time.
// Sort the array according to their first value and find LIS with updated condition of j < i, 
// arr[i].first > arr[j].second