#include<iostream>
using namespace std;

// seperating the 0's, 1's and 2's of array without using any sorting algorithm

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int count[3]={0};
        for(int i{0}; i<n; i++){
            if(a[i]==0) count[0]++;
            else if(a[i]==1) count[1]++;
            else count[2]++;
        }
        int i{0};
        while(count[0]-->0){
            a[i] = 0;
            i++;
        }
        while(count[1]-->0){
            a[i] = 1;
            i++;
        }
        while(count[2]-->0){
            a[i] = 2;
            i++;
        }
    }
};

// Dutch National Flag Algorithm
/*
    [0,___ low-1 ] -> 0         end left
    [low,_____, mid-1] -> 1
    [high+1, _____ , n-1] -> 2 end right
*/

