#include <bits/stdc++.h>
using namespace std;

// Consider a building with innitely many oors. You need to nd the highest oor h from which an
//  egg can be dropped without breaking. Can you do it with O(logh) egg droppings?

// Idea is to first go till some height 2^(h+1) where the egg will break and then do Binary search to
// find the floor between 2^h and 2^(h+1)

bool breaking_function(long long h){
    if(h >= 1e12) return true;
    return false;
}
long long floor_(){
    long long height = 1;
    while(!breaking_function(height)){
        height = height*2;
    }
    long long up = height;
    long long down = height/2;
    long long req;
    while(up >= down){
        req = down + (up - down)/2;
        if(!breaking_function(req)){
            down = req + 1;
        }else{
            up = req - 1;
        }
    }
    return req;
}