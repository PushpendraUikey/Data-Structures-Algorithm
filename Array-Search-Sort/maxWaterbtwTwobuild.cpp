#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array height[] representing the heights of n buildings, the task is to delete n-2 
buildings such that the water that can be trapped between the remaining two building is maximum.
Note: The total water trapped between two buildings is gap between them (number of buildings removed) 
multiplied by height of the smaller building.
*/

// approach to solve the problem is greedy, at each step we reduce the space only from the direction
// where we won't maximize the water trapped if other side is moved in two pointer approach.

class Solution {
  public:
    int maxWater(vector<int> height) {
        int n = height.size();
        if(n < 3) return 0;
        
        int low =0, high = n-1;
        int maxwater=0;
        while(low < high){
            int minih = min(height[low], height[high]);
            int currw = minih * (high-low-1);
            maxwater = max( maxwater, currw);
            
            if(height[low] < height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        
        return maxwater;
    }
};