#include <bits/stdc++.h>
using namespace std;

// Land redistribution:  
// given list of landholdings a1, a2, …, an,  
// given a floor value f,  
// find the right ceiling value c

int ceil(std::vector<int>&land, int&f){
    int totalLand = std::accumulate(land.begin(), land.end(), 0);
    int c = *std::max_element(land.begin(), land.end());
    int mini = f;
    int maxi = c;

    while(mini <= maxi){
        int mid = (mini+maxi)/2;
        int adjustland = 0;

        for(int i=0; i<land.size(); i++){
            if(land[i] < f) adjustland += f;
            else if(land[i] > c) adjustland += c;
            else adjustland += land[i];
        }

        if(totalLand == adjustland){    // found the solution
            c = mid;
            break;
        }else if(adjustland < totalLand){
            mini = mid + 1; // ceiling needs to be increased!
        }else{
            maxi = mid - 1; // ceiling needs to be decreased!
        }
    }

    return c;
}