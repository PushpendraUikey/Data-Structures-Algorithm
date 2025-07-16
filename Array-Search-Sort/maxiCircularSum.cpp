#include <bits/stdc++.h>
using namespace std;

/*
We need to find the maximum sum subarray in a circular array, that is after last element in array next element
will actually be the first element of the array.
So idea is simple: we'll remove the minimum sum subarray from the total sum (since the elements can be negative)
This minimum sum can be calculated using same kadane algorithm if all the elemnts are negated!
*/

int kadane(vector<int>&arr){
    int curr_sum = arr[0];
    int max_sum = arr[0];
    int n = arr.size();

    for(int i=1; i<n; i++){
        curr_sum = max(curr_sum+arr[i], arr[i]);
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

int maximumCircularSum(vector<int>&arr){
    int normalSum = kadane(arr);
    if(normalSum < 0) return normalSum; // circular sum can't be more

    int totalsum=0;
    for(int i=0; i<n; i++){
        totalsum += arr[i];
        arr[i] = -arr[i];   // negate each value so that we'll find maxisum using kadane(which is mini sum of original)
    }

    int maxCircularsum = totalsum + kadane(arr); // since normally minimum sum need to be subtracted we add maxi sum of inverted arr

    return max(maxCircularsum, normalSum);
}