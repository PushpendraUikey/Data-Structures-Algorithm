#include <bits/stdc++.h>
using namespace std;

// Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is 
// possible to reach the destination point using the following valid moves:
// (a, b) -> (a + b, b)
// (a, b) -> (a, a + b)
// Your task is to find if it is possible to reach the destination point using only the desired 
// moves or not

bool solve(int sx, int sy, int dx, int dy, vector<vector<int>>&visited){
    if(sx==dx && sy == dy){
        return true;
    }else if(sx > dx || sy > dy) return false;
    else if(visited[sx][sy] != -1) return visited[sx][sy];
    
    bool canReach = solve(sx+sy, sy, dx, dy, visited)||solve(sx, sy+sx, dx, dy, visited);

    return visited[sx][sy] = canReach;
}
bool reachDestination(int sx, int sy, int dx, int dy) {
    // vector<vector<int>> visited(dx+1, vector<int>(dy+1, -1));

    // return solve(sx, sy, dx, dy, visited);

    //// This one is here a faster implementation-------------
    // idea here is if it is reachable they are made up of m*sx + n*sy only!
    while (dx > sx && dy > sy) {
        // Move backward: reduce the larger coordinate
        if (dx > dy) dx -= dy;
        else dy -= dx;
    }

    // If one coordinate matches, check the other
    return (dx == sx && (dy - sy) % sx == 0) || (dy == sy && (dx - sx) % sy == 0);
}

// Faster implementation comes if you think of it in reverse direction.