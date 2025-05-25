#include <bits/stdc++.h>
using namespace std;

//Given n events with their starting and ending times, find a schedule that 
//includes as many events as possible. It is not possible to select an
//event partially.

// Idea is to select the next possible event that ends as early as possible
// first value is begin timing of any event and second value is end time of any event!
std::vector<std::pair<int, int>> schedule(std::vector<std::pair<int, int> >& __sched){
    std::vector<std::pair<int, int>> ans;
    std::sort(__sched.begin(), __sched.end());

    int beg=0;
    for(auto &x: __sched){
        if(x.second > beg){ 
            beg = x.second;     // new event should not collide with prev
            ans.push_back(x);   // include in the schedule
        }
    }
    return ans;
}