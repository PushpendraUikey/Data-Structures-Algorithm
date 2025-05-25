#include <bits/stdc++.h>
using namespace std;

// we're here measuring the calls and runtime to calculate number of possible ways
// to reach another end of n*n grid from the starting grid covering each square exactly once.

void solution1(std::vector<std::vector<bool>>&visited, int x, int y, int count, int&sol, int&calls){
    calls++;
    visited[x][y] = true;
    int size = visited.size();
    if (x == size - 1 && y == size - 1 && count == size * size) {
        sol++;
        visited[x][y] = false;
        return;
    }

    if(x-1>=0 && !visited[x-1][y]){
        solution1(visited, x-1, y, count+1, sol,calls);
    }
    if(x+1 < size && !visited[x+1][y]){
        solution1(visited, x+1, y, count+1, sol, calls);
    }
    if(y+1<size && !visited[x][y+1]){
        solution1(visited, x, y+1, count+1, sol, calls);
    }
    if(y-1>=0 && !visited[x][y-1]){
        solution1(visited, x, y-1, count+1, sol, calls);
    }
    visited[x][y] = false;
}


// This is optimization one
void solution2(std::vector<std::vector<bool>>&visited, int x, int y, int count, int&sol, int&calls){
    calls++;
    visited[x][y] = true;
    int size = visited.size();
    if (x == size - 1 && y == size - 1 && count == size * size) {
        sol++;
        visited[x][y] = false;
        return;
    }
        if( x == size-1 && y == size-1) {
        visited[x][y] = false;
        return;// prematurely reached end befor traversing all the cells
    }

    if(x-1>=0 && !visited[x-1][y]){
        solution2(visited, x-1, y, count+1, sol,calls);
    }
    if(x+1 < size && !visited[x+1][y]){
        solution2(visited, x+1, y, count+1, sol, calls);
    }
    if(y+1<size && !visited[x][y+1]){
        solution2(visited, x, y+1, count+1, sol, calls);
    }
    if(y-1>=0 && !visited[x][y-1]){
        solution2(visited, x, y-1, count+1, sol, calls);
    }
    visited[x][y] = false;
}

// Optimization 2
void solution3(std::vector<std::vector<bool>>&visited, int x, int y, int count, int&sol, int&calls){
    calls++;
    visited[x][y] = true;
    int size = visited.size();
    if (x == size - 1 && y == size - 1 && count == size * size) {
        sol++;
        visited[x][y] = false;
        return;
    }
    if( x == size-1 && y == size-1) {
        visited[x][y] = false;
        return;// prematurely reached end befor traversing all the cells
    }
    if((x < 1 || x == size-1) && y != 0 && y!=size-1 && !visited[x][y-1]&& !visited[x][y+1]){
        visited[x][y] = false;
        return; // it is partitioned into two parts hence solution won't exist on going either way
    }
    if((y < 1 || y == size-1) && x != 0 && x !=size-1 && !visited[x-1][y]&& !visited[x+1][y]){
        visited[x][y] = false;
        return; // it is partitioned into two parts hence solution won't exist on going either way
    }

    if(x-1>=0 && !visited[x-1][y]){
        solution3(visited, x-1, y, count+1, sol,calls);
    }
    if(x+1 < size && !visited[x+1][y]){
        solution3(visited, x+1, y, count+1, sol, calls);
    }
    if(y+1<size && !visited[x][y+1]){
        solution3(visited, x, y+1, count+1, sol, calls);
    }
    if(y-1>=0 && !visited[x][y-1]){
        solution3(visited, x, y-1, count+1, sol, calls);
    }
    visited[x][y] = false;
}

// This is optimization 4
void solution4(std::vector<std::vector<bool>>&visited, int x, int y, int count, int&sol, int&calls){
    calls++;
    visited[x][y] = true;
    int size = visited.size();
    if (x == size - 1 && y == size - 1 && count == size * size) {
        sol++;
        visited[x][y] = false;
        return;
    }
    if( x == size-1 && y == size-1) {
        visited[x][y] = false;
        return;// prematurely reached end befor traversing all the cells
    }
    if((x < 1 || x == size-1) && y != 0 && y!=size-1 && !visited[x][y-1]&& !visited[x][y+1]){
        visited[x][y] = false;
        return; // it is partitioned into two parts hence solution won't exist on going either way
    }
    if((y < 1 || y == size-1) && x != 0 && x !=size-1 && !visited[x-1][y]&& !visited[x+1][y]){
        visited[x][y] = false;
        return; // it is partitioned into two parts hence solution won't exist on going either way
    }

    if(x>0&&y>0&&x<size-1&&y<size-1){
        if(visited[x][y+1] && visited[x][y-1] && !visited[x-1][y] && !visited[x+1][y]){
            visited[x][y] = false;
            return;
        }
        if(!visited[x][y+1] && !visited[x][y-1] && visited[x-1][y] && visited[x+1][y]){
            visited[x][y] = false;
            return;
        }
    }

    if(x-1>=0 && !visited[x-1][y]){
        solution4(visited, x-1, y, count+1, sol,calls);
    }
    if(x+1 < size && !visited[x+1][y]){
        solution4(visited, x+1, y, count+1, sol, calls);
    }
    if(y+1<size && !visited[x][y+1]){
        solution4(visited, x, y+1, count+1, sol, calls);
    }
    if(y-1>=0 && !visited[x][y-1]){
        solution4(visited, x, y-1, count+1, sol, calls);
    }
    visited[x][y] = false;
}
int main() {
    int n;
    cin >> n;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int sol = 0;
    int calls=0;
    // Start measuring time
    auto start_time = chrono::high_resolution_clock::now();

    visited[0][0] = true;
    solution4(visited, 0, 0, 1, sol, calls);

    // Stop measuring time
    auto end_time = chrono::high_resolution_clock::now();

    // Calculate duration in milliseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    cout << "Number of solutions to the problem: " << sol << "\n";
    cout << "Number of calls to the function: " << calls << "\n";
    cout << "Time taken: " << duration << " ms" << "\n";

    return 0;
}