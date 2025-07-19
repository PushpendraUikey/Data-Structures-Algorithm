#include <bits/stdc++.h>
using namespace std;

/*
An array consists of element 1 to some k, such that if k is the maximum value in the array all the elemtns
from 1 to k are present with only one of them being repeated. Find it.

Observation: k can be at max n-1 if n is size of array
We'll be using cycle detection technique in linked list to find that value.
Since other than repeating all elements are distinct hence index pointed by them can't 
create a cycle but the repeating elements can and they will.
*/

int findRepeating(vector<int>&arr){
    int slow = arr[0], fast=arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);       // slow and fast would be pointing to the same ele inside cycle

    slow = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

// Extension: if the elements start with 0 then add 1 whenever updating slow and fast pointers.
// otherwise this testcase would fail: 1,0,2,2,2 and 0,2,1,3,5,4,6,2