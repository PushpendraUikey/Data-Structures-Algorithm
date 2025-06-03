#include <bits/stdc++.h>
using namespace std;

//given n tasks with durations and deadlines and our task is to choose an order to 
//perform the tasks. For each task, we earn d-x points where d is the task’s deadline 
//and x is the moment when we finish the task.

//a correct greedy strategy is to simply perform the tasks
//sorted by their durations in increasing order
// for correctness take two tasks with duration a and b; a>b

//first value in vector is duration(time it takes) and second value is deadline(time it needs to be finished by)
int score(std::vector<std::pair<int, int>>& __tasks){
    std::sort(__tasks.begin(), __tasks.end());
    int moment=0;
    int total=0;
    for(auto&d: __tasks){
        moment += d.first;  // time passed before task completion
        total += (d.second-moment); // deadline-x(moment)
    }
    return total;
}


// Another variant would be where we're asked to minimize that <total>, there we'd simply 
// execute the task with earliest deadline first. This greedy approach indeed works.