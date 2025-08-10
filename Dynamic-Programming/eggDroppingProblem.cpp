#include <bits/stdc++.h>
using namespace std;

// We need to find out the minimum number of trials we'd need in the worst case given 
// some number of eggs and floors to find out the threshold floor.
// A threshold floor is the floor, egg dropped from which breaks but dropped from the below floor doesn't

/*
The following is a description of the instance of this famous puzzle involving n=2 eggs and a building 
with k=36 floors. Suppose that we wish to know which stories in a 36-storey building are safe to drop 
eggs from, and which will cause the eggs to break on landing. We make a few assumptions:
.....An egg that survives a fall can be used again. 
.....A broken egg must be discarded. 
.....The effect of a fall is the same for all eggs. 
.....If an egg breaks when dropped, then it would break if dropped from a higher floor. 
.....If an egg survives a fall then it would survive a shorter fall. 
.....It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor 
do not cause an egg to break. If only one egg is available and we wish to be sure of obtaining the right 
result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if 
it survives, drop it from the second-floor window. Continue upward until it breaks. In the worst case, 
this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings 
that is guaranteed to work in all cases? 

The problem is not actually to find the critical floor, but merely to decide floors from which eggs 
should be dropped so that the total number of trials are minimized.
*/


int threshold_floor(int e, int f){
    if(e==1) return f;
    if(f==1) return 1;
    if(f==0) return 0;

    int res = INT_MAX;
    for(int i=1; i<=f; i++){
        res = min(
            max(threshold_floor(i-1, e-1), // egg breaks
                threshold_floor(f-i, e)  // egg doesn't breaks
            ) + 1,
            res
        );
    }

    return res;
}

// little optimized code
class Solution {
    int solve(int e, int f, vector<vector<int>>& vec){
        if(e==1) return vec[e][f] = f;
        if(f==1) return vec[e][f] = 1;
        if(f==0) return vec[e][f] = 0;
        
        if(vec[e][f] != -1) return vec[e][f];
        int res = INT_MAX;
        
        for(int x=1; x<=f; x++){
            res = min( 
                    res, 
                    max(solve(e-1, x-1, vec), solve(e, f-x, vec))+1
                );
        }
        
        return vec[e][f] = res;
    }
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        vector<vector<int>> vec(n+1, vector<int>(k+1, -1));
        return solve(n, k, vec);
    }
};

// DP based solution
int eggDrop(int e, int f){
    int dp[e+1][f+1];

    for(int i=0; i<=e; i++){
        dp[i][1] = 1;   // only 1 floor then 1 trial req
        dp[i][0] = 0;   // 0 floors then 0 trial req
    }
    for(int j=0; j<=f; j++){
        dp[0][j] = INT_MAX; // 0 eggs then infinite trials req
        dp[1][j] = j;   // 1 egg then current number of floor trials req.
    }

    for(int i=2; i<=e; i++){
        for(int j=2; j<=f; j++){
            dp[i][j] = INT_MAX;
            for(int x=1; x<=j; x++){          //egg break   //egg doesn't break
                dp[i][j] = min(dp[i][j], 1+max(dp[i-1][x-1], dp[i][j-x]));
            }
        }
    }
    return dp[e][f];
}

// Faster code
/*
Approach: Instead of fixing floors k and finding min moves,
we fix moves m and find how many floors we can test with given eggs.
It’s like changing the axis you solve the DP along.
*/
class Solution {
public:
    int eggDrop(int eggs, int floors) {
        vector<long long> dp(eggs + 1, 0);
        int moves = 0;
        
        while (dp[eggs] < floors) {
            moves++;
            for (int e = eggs; e >= 1; e--) {
                dp[e] = dp[e] + dp[e - 1] + 1;
            }
        }
        
        return moves;
    }
};
