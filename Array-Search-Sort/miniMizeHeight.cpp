#include<bits/stdc++.h>
using namespace std;

//// each array value represents the height of the tower, and a value "k" is given to you, you 
/// have to perform the following operation exact once to each "add k or sub k" from the height
/// and then give the mini possible height diff b/w largest and smallest modified also 
/// no modified should be negative.

//// Don't have the proof of correctness of the algorithm

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {

        int n = arr.size();
        if(n == 1) return 0; /// one element only then the diff in height is 0
        
        /// sort the array;
        sort(arr.begin(), arr.end());
        
        //// initital diff between largest and smallest values
        int ans = arr[n-1] - arr[0];
        
        //// Consider the largest and smallest possible heights
        
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;     //// since we want to find min possi diff
                //// between heights thus we'll reduce height of large tower
                /// and increase the height of small tower
                /// but we'll take the consecutive towers only.
        
        
        //// Travesrisng throug the array and calculate the minimum difference
        // since the array is sorted we are looking for minimum difference in two consecutive elements
        for(int i=0; i<n-1; i++){
            int maxHeight = max(largest, arr[i]+k);
            int minHeight = min(smallest, arr[i+1]-k);
            
            if(minHeight < 0) continue; // skip the negative heights 
            
            //// anyway in the next iteration it's height is going to be inc under maxHeight condn
            ans = min(ans, maxHeight - minHeight);
        }
        
        return ans;
    }
};