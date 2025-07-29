#include<bits/stdc++.h>
using namespace std;

//As an example, consider a problem where we are given a list of n numbers
//and a number x, and we want to find out if it is possible to choose some numbers
//from the list so that their sum is x.


// Divide the problem into two subparts and generate the answer by combining them!

// normal way to solve takes O(2^n) time
void sumGenerator(std::vector<int>&__sums, std::vector<int>&__numbers, int k, int& sum){
    if(k==__numbers.size()){
        __sums.push_back(sum);
        return;
    }
    sumGenerator(__sums, __numbers, k+1, sum);
    sum += __numbers[k];
    sumGenerator(__sums, __numbers, k+1, sum);
    sum -= __numbers[k];
    // if(k==__numbers.size()){
    //     __sums.push_back(sum);
    //     return;
    // }

    // for(int i=0; i<__numbers.size(); ++i){
    //     if(!visited[i]){
    //         sum += __numbers[i];
    //         visited[i] = true;
    //         sumGenerator(__sums, __numbers, visited, k+1, sum);
    //         sum -= __numbers[i];
    //         visited[i] = false;
    //     }
    // }
}

bool isPossible(std::vector<int>& __numbers, int x){
    int size = __numbers.size();
    std::vector<int> first_half(size/2), second_half(size-size/2);
    // std::vector<bool> visited_first(size/2, false), visited_second(size-size/2, false);

    for(int i=0; i<__numbers.size(); ++i){
        if(i<size/2){
            first_half[i] = __numbers[i];
        }else{
            second_half[i] = __numbers[i];
        }
    }

    // Generate sum using sumGenerator and check if the sum of any two number in both the list equals 'x'

}