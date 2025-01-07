#include <bits/stdc++.h>
using namespace std;

//--------------------------------Important Divide&Conquer-----------------------------

// just follow the hanoi's step
// problem is solved using divide&conquer technique, where first move n-1 blocks to
// auxillary bar, and secondly move the nth(largest) to the destination.
void Hanoi(vector<vector<int>>&ans, int s,int d, int a, int n){
    if(n==1){
      ans.push_back({s, d});    // nth disk move to the dest(largest):part1
      return;
    }
    Hanoi(ans, s, a, d, n-1);   // firstly move n-1 disks to aux bar:part2
    ans.push_back({s, d});
    Hanoi(ans, a, d, s, n - 1); // then move those auxillaried to dest
}
vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> ans;

    Hanoi(ans, 1, 2, 3, n);
    return ans;
}