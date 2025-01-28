#include <bits/stdc++.h>
using namespace std;

#define ll long long


//  Non-dominated points. For points in 2 dimensions, we say (a,b) dominates (c,d) if a>=c and b>=d.
//  Given a set of n points in 2 dimensions, design an O(nlogn) time algorithm to compute the set of
//  points which are not dominated by any other point.

// we need the points whose both coordinates can't be surpassed by any other corrdinates.
std::vector<std::pair<int, int>> nonDominatePoints(std::vector<std::pair<int, int>>& points) {
    // Sort points by first coordinate (ascending),
    // break ties by second coordinate (descending)
    std::sort(points.begin(), points.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    // Step 2: Scan from right to left to find non-dominated points
    std::vector<std::pair<int, int>> result;
    int maxY = INT_MIN;

    // This is actually a very clever algorithm, because first we're adding the coordinates 
    // with greater 'x-cordi' then if we encounter coordinates with global maxi 'y-coordi'
    // we're adding those too into result because no 'x-cordi' in left side of that coordinates
    // can surpass it and no 'y-cordi' in the right can surpass it making it the "non-dominating point".
    for (auto it = points.rbegin(); it != points.rend(); ++it) {
        if (it->second > maxY) {
            result.push_back(*it); // Add the point as it's non-dominated
            maxY = it->second;    // Update the maximum y value
        }
    }

    // Since we processed points in reverse order, reverse the result to maintain the original order
    std::reverse(result.begin(), result.end());
    return result;
}