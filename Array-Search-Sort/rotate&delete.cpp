#include<bits/stdc++.h>
using namespace std;

/// Following is the solution to the problem where we have to rotate the array by one and delete the 
/// k^th element from the end where "k" is step of rotation.
// Return: last element which will left


class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        deque<int> dq;
        for(auto& i:arr){
            dq.push_back(i);
        }
        int step = 1;
        while(dq.size()>1){
            int k = step;
            if(step > dq.size()){   //// if step beomes more than size than we've to remove the last element
                dq.pop_back();
            }else{
                int v = dq.back();
                dq.pop_back();
                dq.push_front(v);
                
                dq.erase(dq.end()-step);    //// remove the step'th position element from the end.
            }
           step++;
        }
        
        return dq.front();
        
    }
};