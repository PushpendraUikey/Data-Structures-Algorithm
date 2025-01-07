#include <bits/stdc++.h>
using namespace std;

// This is NP-hard problem

// You are a coach of a group consisting of 'N' students. The ith student has a strength Arr[i]. 
// For a Tug of War game, you want to divide students into two teams of equal size (If N is odd, 
// then size of one team should be (N-1)/2 and size of other team should be (N+1)/2). You want 
// a game that is fun, for this the absolute difference between the team’s strength should be as 
// minimum as possible. A team's strength is the sum of the strengths of the students in the team.


// A brute force solution, checking all the possiblities
// Recursive function to explore partitions
void backtrack(vector<int>& arr, int idx, vector<int>& team1, vector<int>& team2, 
    int& minDiff, int& totalSum) {
    // If the partition sizes are correct
    if (team1.size() == arr.size() / 2 && team2.size() == (arr.size() + 1) / 2) {
        int sum1 = accumulate(team1.begin(), team1.end(), 0);
        int sum2 = totalSum - sum1;
        minDiff = min(minDiff, abs(sum1 - sum2));
        return;
    }

    // Base case: All students considered
    if (idx >= arr.size()) return;

    // Option 1: Add the student to team1 if its size is within limits
    if (team1.size() < arr.size() / 2) {
        team1.push_back(arr[idx]);
        backtrack(arr, idx + 1, team1, team2, minDiff, totalSum);
        team1.pop_back();
    }

    // Option 2: Add the student to team2 if its size is within limits
    if (team2.size() < (arr.size() + 1) / 2) {
        team2.push_back(arr[idx]);
        backtrack(arr, idx + 1, team1, team2, minDiff, totalSum);
        team2.pop_back();
    }
}

int tugOfWar(vector<int> &arr, int n)
{
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // Initialize variables for backtracking
    vector<int> team1, team2;
    int minDiff = INT_MAX;

    // Call recursive function
    backtrack(arr, 0, team1, team2, minDiff, totalSum);

    return minDiff;
}