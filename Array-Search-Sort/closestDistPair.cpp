#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

// brute force 
long closestPair(pair<int, int>* coordinates, int n)
{
    long mini = LONG_MAX; 

    for(int i=0; i<n; i++){
        pair<int, int> c1 = coordinates[i];
        for(int j=i+1; j<n; j++){
            pair<int, int> c2 = coordinates[j];
            long dist = (long)(c1.first-c2.first)*(c1.first-c2.first) + (long)(c1.second-c2.second)*(c1.second-c2.second);
            mini = min(dist, mini);
        }
    }
    return mini;
}



// Optimized. (Not written by me)
long distSquared(pair<int, int> p1, pair<int, int> p2) {
    return (long)(p1.first - p2.first) * (p1.first - p2.first) +
           (long)(p1.second - p2.second) * (p1.second - p2.second);
}

long closestPairUtil(vector<pair<int, int>> &points, int left, int right) {
    if (right - left <= 3) { // Base case for small number of points
        long mini = LONG_MAX;
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j < right; j++) {
                mini = min(mini, distSquared(points[i], points[j]));
            }
        }
        return mini;
    }

    int mid = (left + right) / 2;
    pair<int, int> midPoint = points[mid];

    long leftDist = closestPairUtil(points, left, mid);
    long rightDist = closestPairUtil(points, mid, right);

    long d = min(leftDist, rightDist);

    // Create a strip and check for closer points across the divide
    vector<pair<int, int>> strip;
    for (int i = left; i < right; i++) {
        if (abs(points[i].first - midPoint.first) < d) {
            strip.push_back(points[i]);
        }
    }

    // Sort the strip by y-coordinate
    sort(strip.begin(), strip.end(),
         [](pair<int, int> p1, pair<int, int> p2) { return p1.second < p2.second; });

    // Compare points in the strip
    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size() && (strip[j].second - strip[i].second) < d; j++) {
            d = min(d, distSquared(strip[i], strip[j]));
        }
    }

    return d;
}

long closestPair(pair<int, int> *coordinates, int n) {
    vector<pair<int, int>> points(coordinates, coordinates + n);
    // Sort points by x-coordinate
    sort(points.begin(), points.end());
    return closestPairUtil(points, 0, n);
}